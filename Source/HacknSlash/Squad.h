// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Pawn.h"
#include "MyEnums.h"
#include "Squad.generated.h"

class AHacknSlashCharacter;
class ATargetPoint;

USTRUCT(BlueprintType)
struct FSquadFormation
{
	GENERATED_USTRUCT_BODY()

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Formation")
		EFormationType FormationType;
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Formation")
		int32 Width;
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Formation")
		int32 Length;

	FSquadFormation() {
		FormationType = EFormationType::Ft_Close;			
		Width = 3;
		Length = 4;
	};
};

UCLASS()
class HACKNSLASH_API ASquad : public APawn
{
	GENERATED_BODY()

public:
	// Sets default values for this pawn's properties
	ASquad();

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Squad", meta = (AllowPrivateAccess = "true"))
		class UStaticMeshComponent* Mesh;
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Squad")
		int32 MaxMembers = 10;
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Squad")
		AHacknSlashCharacter* Leader;
	UPROPERTY(VisibleAnywhere, BlueprintReadWrite, Category = "Squad", meta = (AllowPrivateAccess = "true"))
		TArray <AHacknSlashCharacter*> squadMembers;

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = "Squad")
		EFactions Faction;
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Squad")
		ESquadOrders CurrentOrder;
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Squad")
		ATargetPoint* myTargetPoint;
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Squad")
		TArray <ATargetPoint*> PointsOfInterest;

	UPROPERTY(VisibleAnywhere, BlueprintReadWrite, Category = "Squad", meta = (AllowPrivateAccess = "true"))
		TArray <ASquad*> EnemiesInSight;
	UPROPERTY(VisibleAnywhere, BlueprintReadWrite, Category = "Squad", meta = (AllowPrivateAccess = "true"))
		TArray <ASquad*> AlliesInSight;
	UPROPERTY(VisibleAnywhere, BlueprintReadWrite, Category = "Squad", meta = (AllowPrivateAccess = "true"))
		ASquad* PriorityEnemy;
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Squad")
		FSquadFormation myFormation;


protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;

	// Called to bind functionality to input
	virtual void SetupPlayerInputComponent(class UInputComponent* PlayerInputComponent) override;

	
	
};
