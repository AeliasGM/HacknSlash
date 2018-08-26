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
	St_UnableToAttack	UMETA(DisplayName = "UnableToAttack"),
	St_Eager			UMETA(DisplayName = "Eager"),
	St_Neutral			UMETA(DisplayName = "Neutral"),
	St_Cautious			UMETA(DisplayName = "Cautious")

};

UENUM(BlueprintType)		//"BlueprintType" is essential to include
enum class EFactions : uint8
{
	F_Good		UMETA(DisplayName = "Good"),
	F_Bad		UMETA(DisplayName = "Bad")

};

UENUM(BlueprintType)		//"BlueprintType" is essential to include
enum class ESquadOrders : uint8
{
	So_StandFormation	UMETA(DisplayName = "StandFormation"),
	So_Attack			UMETA(DisplayName = "Attack"),
	So_Move				UMETA(DisplayName = "Move"),
	So_Defend			UMETA(DisplayName = "Defend"),
	So_Retreat			UMETA(DisplayName = "Retreat")
};

//TODO add other formation types
UENUM(BlueprintType)		//"BlueprintType" is essential to include
enum class EFormationType : uint8
{
	Ft_Wide		UMETA(DisplayName = "Wide"),
	Ft_Close	UMETA(DisplayName = "Close"),
};
