// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
//#include "GameFramework/PlayerState.h"
#include "CharacterStats.generated.h"

/*
  Moved to character vitals
 
UENUM(BlueprintType)		//"BlueprintType" is essential to include
enum class EVitalNames : uint8
{
	VN_HP		UMETA(DisplayName = "Health"),
	VN_Stamina 	UMETA(DisplayName = "Stamina"),
	VN_Morale	UMETA(DisplayName = "Morale")
	//NumberOfItems
};

USTRUCT(BlueprintType)
//USTRUCT()
struct FVital
{
	GENERATED_USTRUCT_BODY()

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = Stats)
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
	
	
	FVital (EVitalNames VitalName, float mValue, float cValue, float rRate) {
		StatName = VitalName;
		MaxValue = mValue;
		CurentValue = cValue;
		RegenRate = rRate;
		
	};
	
};

UCLASS(config = Game)
class HACKNSLASH_API FCharacterStats {
private:
	bool bStat = true;
};
//	GENERATED_BODY()
	
public:

	//** Verification functions 
	UFUNCTION(BlueprintCallable, Category = "Stats")
		int32 GetStatInArray(TArray <FVital> MyVitals, const EVitalNames vitalName);

	//	UFUNCTION(BlueprintCallable, Category = "Stats")
	//	bool CheckVitals(const TArray <UVitals>  myVitals);

	//** Vital Setters
	UFUNCTION(BlueprintCallable, Category = "Stats")
		void SetMaxValue(TArray <FVital> MyVitals, const EVitalNames vitalName, const float maxValue);

	UFUNCTION(BlueprintCallable, Category = "Stats")
		void SetCurrentValue(TArray <FVital> MyVitals, const EVitalNames vitalName, const float currentValue);

	UFUNCTION(BlueprintCallable, Category = "Stats")
		void StatAddValue(TArray <FVital> MyVitals, const EVitalNames vitalName, const float AddAmount);

	//** Vital Getters
	UFUNCTION(BlueprintCallable, Category = "Stats")
		float GetMaxValue(TArray <FVital> MyVitals, const EVitalNames vitalName);

	UFUNCTION(BlueprintCallable, Category = "Stats")
		float GetCurrentValue(TArray <FVital> MyVitals, const EVitalNames vitalName);

	UFUNCTION(BlueprintCallable, Category = "Stats")
		float GetCurrentPercent(TArray <FVital> MyVitals, const EVitalNames vitalName);
};
*/
