#pragma once

#include "CoreMinimal.h"
#include "MyEnums.generated.h"



UENUM(BlueprintType)		//"BlueprintType" is essential to include
enum class EVitalNames : uint8
{
	VN_HP		UMETA(DisplayName = "Health"),
	VN_Stamina 	UMETA(DisplayName = "Stamina"),
	VN_Morale	UMETA(DisplayName = "Morale"),
	NumberOfItems
};

//TODO add more character States
UENUM(BlueprintType)		//"BlueprintType" is essential to include
enum class ECharacterStates : uint8
{
	St_Eager	UMETA(DisplayName = "Eager"),
	St_Neutral	UMETA(DisplayName = "Neutral"),
	St_Cautious	UMETA(DisplayName = "Cautious")

};