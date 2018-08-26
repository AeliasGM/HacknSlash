// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Components/ActorComponent.h"
#include "MyEnums.h"
#include "TacticalComponent.generated.h"

class AHacknSlashCharacter;
class ASquad;

UCLASS( ClassGroup=(Custom), meta=(BlueprintSpawnableComponent) )
class HACKNSLASH_API UTacticalComponent : public UActorComponent
{
	GENERATED_BODY()

public:	
	// Sets default values for this component's properties
	UTacticalComponent();

protected:
	// Called when the game starts
	virtual void BeginPlay() override;

public:	
	// Called every frame
	virtual void TickComponent(float DeltaTime, ELevelTick TickType, FActorComponentTickFunction* ThisTickFunction) override;

	/** Variables*/
public:
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Tactical")
		EFactions myFaction;
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Tactical")
		ASquad* mySquad;
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Tactical")
		ESquadOrders myOrder;
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Tactical")
		FIntVector mySquadPosition;

	UPROPERTY(VisibleAnywhere, BlueprintReadWrite , Category = "Tactical", meta = (AllowPrivateAccess = "true"))
		TArray <AHacknSlashCharacter*> Enemies;
	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = "Tactical", meta = (AllowPrivateAccess = "true"))
		TArray <AHacknSlashCharacter*> Allies;

};
