// Fill out your copyright notice in the Description page of Project Settings.

#include "CharacterStats.h"

UCharacterStats::UCharacterStats()
{
	// Set this component to be initialized when the game starts, and to be ticked every frame.  You can turn these features
	// off to improve performance if you don't need them.
	PrimaryComponentTick.bCanEverTick = true;

	// ...
}

void UCharacterStats::BeginPlay()
{
	Super::BeginPlay();
	//check if Vitals were initialized
	if (!CheckVitals (Vitals))
		UE_LOG(LogTemp, Error, TEXT("%s has Uninitialized Stats"), *this->GetOwner ()->GetName ());

	GetWorld()->GetTimerManager().SetTimer(recoveryTimer, this, &UCharacterStats::RestorationTimerEnd, 1.f, false);

}

void UCharacterStats::TickComponent(float DeltaTime, ELevelTick TickType, FActorComponentTickFunction * ThisTickFunction)
{
	Super::TickComponent(DeltaTime, TickType, ThisTickFunction);
}

void UCharacterStats::RestorationTimerEnd()
{
	// performm stats current value recovery
	for (auto &Vital : Vitals) {
		StatModifyCurrent(Vital.StatName, 1, Vital.RegenRate);
	}

	//Update myCurrentState
 	CharacterState = UCharacterStats::GetMyCurrentState();	

	//Reset timer
	GetWorld()->GetTimerManager().SetTimer(recoveryTimer, this, &UCharacterStats::RestorationTimerEnd, 1.f, false);


}

int32 UCharacterStats::GetStatInArray(const EVitalNames vitalName) const 
{
	int32 index = 0;

	for (int32 i = 0; i <= Vitals.Num(); i++) {
		if (vitalName == Vitals[i].StatName)
		{
			index = i;
			break;
		}
	}
	return index;
}

bool UCharacterStats::CheckVitals(const TArray <FVital>  myVitals)
{
	for (int32 i = 0; i < (int32)EVitalNames::NumberOfItems; i++) 
	{
		if (myVitals[i].StatName != EVitalNames(i))
			return false;
	}
	return true;
}

//** Vital Setters
void UCharacterStats::SetMaxValue(const EVitalNames vitalName, const float maxValue)//, float&  maxValue)
{
	if (CheckVitals (Vitals))
	Vitals[GetStatInArray(vitalName)].MaxValue = maxValue;
}

void UCharacterStats::SetCurrentValue(const EVitalNames vitalName, const float currentValue)
{
	if (CheckVitals(Vitals))
	Vitals[GetStatInArray(vitalName)].CurentValue = currentValue;
}

void UCharacterStats::SetRecoveryRate(const EVitalNames vitalName, const float recoveryRate)
{
	if (CheckVitals(Vitals))
	Vitals[GetStatInArray(vitalName)].RegenRate = recoveryRate;
}
//** Vital Getters
float UCharacterStats::GetMaxValue(const EVitalNames vitalName) const 
{
	return Vitals[GetStatInArray(vitalName)].MaxValue;
}

float UCharacterStats::GetCurrentValue(const EVitalNames vitalName) const
{
	return Vitals[GetStatInArray(vitalName)].CurentValue;
}

float UCharacterStats::GetCurrentPercent(const EVitalNames vitalName) const
{
	float result = Vitals[GetStatInArray(vitalName)].CurentValue / Vitals[GetStatInArray(vitalName)].MaxValue;
	return result;
}

void UCharacterStats::StatModifyCurrent(const EVitalNames vitalName, const float Multiplier, const float AddAmount)
{
	//compare to max value
	if (CheckVitals(Vitals))
	SetCurrentValue(vitalName, 
		FMath::Clamp(Vitals[GetStatInArray(vitalName)].CurentValue + 
			AddAmount*Multiplier, 
			0.0f, 
			GetMaxValue(vitalName)));
}

ECharacterStates UCharacterStats::GetMyCurrentState() const
{
	ECharacterStates myState = ECharacterStates::St_Eager;

	float myHpRate = GetCurrentPercent(EVitalNames::VN_HP);
	float myStaRate = GetCurrentPercent(EVitalNames::VN_Stamina);

	float _lowPoint = 0.3f;
	float _medPoint = 0.6f;

	if (myStaRate<AttackCost) myState = ECharacterStates::St_UnableToAttack;
	else if (myHpRate < _lowPoint && myStaRate < _lowPoint) myState = ECharacterStates::St_Cautious;
	else if (myHpRate < _lowPoint && myStaRate < _medPoint) myState = ECharacterStates::St_Cautious;
	else if (myHpRate < _lowPoint && myStaRate >= _medPoint) myState = ECharacterStates::St_Cautious;
	else if (myHpRate < _medPoint && myStaRate < _lowPoint) myState = ECharacterStates::St_Neutral;
	else if (myHpRate < _medPoint && myStaRate < _medPoint) myState = ECharacterStates::St_Neutral;
	else if (myHpRate < _medPoint && myStaRate >= _medPoint) myState = ECharacterStates::St_Eager;
	else if (myHpRate >= _medPoint && myStaRate < _lowPoint) myState = ECharacterStates::St_Neutral;
	else if (myHpRate >= _medPoint && myStaRate < _medPoint) myState = ECharacterStates::St_Cautious;
	else myState = ECharacterStates::St_Eager;

	return myState;
}