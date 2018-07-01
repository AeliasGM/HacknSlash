// Fill out your copyright notice in the Description page of Project Settings.

#include "CharacterStats.h"

/**
* Moved to character vitals

int32 ACharacterStats::GetStatInArray(TArray <FVital> MyVitals, const EVitalNames vitalName)//, int32& index) 
{
	int32 index;

	for (int32 i = 0; i <= MyVitals.Num(); i++) {
		if (vitalName == MyVitals[i].StatName)
		{
			index = i;
			break;
		}
	}
	return index;
}
/**
bool UVitals::CheckVitals(const TArray <UVitals>  myVitals)
{

for (int i = 0; i < (int)EVitalNames::NumberOfItems; i++)
{
if (myVitals[i]::StatName = EVitalNames (i))
}

return true;
}

//** Vital Setters
void ACharacterStats::SetMaxValue(TArray <FVital> MyVitals, const EVitalNames vitalName, const float maxValue)//, float&  maxValue)
{
	//maxValue = 0.1f;
	MyVitals[GetStatInArray(MyVitals, vitalName)].MaxValue = maxValue;
}

void ACharacterStats::SetCurrentValue(TArray <FVital> MyVitals, const EVitalNames vitalName, const float currentValue)
{
	MyVitals[GetStatInArray(MyVitals, vitalName)].CurentValue = currentValue;
}

//** Vital Getters
float ACharacterStats::GetMaxValue(TArray <FVital> MyVitals, const EVitalNames vitalName)//, float&  maxValue)
{
	//maxValue = 0.1f;
	return MyVitals[GetStatInArray(MyVitals, vitalName)].MaxValue;
}

float ACharacterStats::GetCurrentValue(TArray <FVital> MyVitals, const EVitalNames vitalName)
{
	return MyVitals[GetStatInArray(MyVitals, vitalName)].CurentValue;
}

float ACharacterStats::GetCurrentPercent(TArray <FVital> MyVitals, const EVitalNames vitalName)
{
	float result = MyVitals[GetStatInArray(MyVitals, vitalName)].CurentValue / MyVitals[GetStatInArray(MyVitals, vitalName)].MaxValue;
	return result;
}

void ACharacterStats::StatAddValue(TArray <FVital> MyVitals, const EVitalNames vitalName, const float AddAmount)
{
	//compare to max value
	SetCurrentValue(MyVitals, vitalName, MyVitals[GetStatInArray(MyVitals, vitalName)].CurentValue + AddAmount);
}
*/


