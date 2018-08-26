// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "MyEnums.h"
#include "Components/ActorComponent.h"
#include "Engine/World.h"
//#include "GameFramework/PlayerState.h"
#include "CharacterStats.generated.h"

USTRUCT(BlueprintType)
struct FVital
{
	GENERATED_USTRUCT_BODY()

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Stats")
		EVitalNames StatName;
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Stats")
		float MaxValue;
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Stats")
		float CurentValue;
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Stats")
		float RegenRate;


	FVital() {
		StatName = EVitalNames::VN_HP;
		MaxValue = 100.f;
		CurentValue = 100.f;
		RegenRate = 1.f;
	};
};

UCLASS(ClassGroup = (Custom), meta = (BlueprintSpawnableComponent))
class HACKNSLASH_API UCharacterStats: public UActorComponent {
	GENERATED_BODY()
public:
	// Sets default values for this component's properties
	UCharacterStats();

protected:
	// Called when the game starts
	virtual void BeginPlay() override;

protected:
	// Called every frame
	virtual void TickComponent(float DeltaTime, ELevelTick TickType, FActorComponentTickFunction* ThisTickFunction) override;
	
	// Timer used for character stat  current value restoration
	UFUNCTION(BlueprintCallable, Category = "Stats")
		void RestorationTimerEnd();

	//** Character Variables
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Stats")
		TArray <FVital> Vitals;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Stats")
		float AttackCost;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Stats")
		float BaseAttackDamage;

	//TODO change character state to read only in BP
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Stats")
		ECharacterStates CharacterState;

	//** Verification functions
	UFUNCTION(BlueprintCallable, Category = "Stats")
		int32 GetStatInArray(const EVitalNames vitalName) const;

	UFUNCTION(BlueprintCallable, Category = "Stats")
		bool CheckVitals(const TArray <FVital>  myVitals);

	//** Vital Setters
	UFUNCTION(BlueprintCallable, Category = "Stats")
		void SetMaxValue(const EVitalNames vitalName, const float maxValue);

	UFUNCTION(BlueprintCallable, Category = "Stats")
		void SetCurrentValue(const EVitalNames vitalName, const float currentValue);

	UFUNCTION(BlueprintCallable, Category = "Stats")
		void SetRecoveryRate(const EVitalNames vitalName, const float recoveryRate);

	UFUNCTION(BlueprintCallable, Category = "Stats")
		void StatModifyCurrent(const EVitalNames vitalName, const float Multiplier, const float AddAmount);

	//** Vital Getters
	UFUNCTION(BlueprintCallable, Category = "Stats")
		float GetMaxValue(const EVitalNames vitalName) const;

	UFUNCTION(BlueprintCallable, Category = "Stats")
		float GetCurrentValue(const EVitalNames vitalName) const;

	UFUNCTION(BlueprintCallable, Category = "Stats")
		float GetCurrentPercent(const EVitalNames vitalName) const;

	UFUNCTION(BlueprintCallable, Category = "Stats")
		ECharacterStates GetMyCurrentState() const;

private:
	FTimerHandle recoveryTimer;


};

