// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Components/ActorComponent.h"
#include "Components/SphereComponent.h"
#include "MyEnums.h"
#include "TacticalComponent.generated.h"

class AHacknSlashCharacter;

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

	//Overlap
	UFUNCTION()
		void BeginOverlap(USphereComponent* DangerSphere,
			AActor* OtherActor,
			UPrimitiveComponent* OtherComp,
			int32 OtherBodyIndex,
			bool bFromSweep,
			const FHitResult &SweepResult);
		
	/** Variables*/
public:
	/** sphere component */
	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = Tactical, meta = (AllowPrivateAccess = "true"))
		class USphereComponent* DangerSphere;

	UPROPERTY(Category = Initialize, EditAnywhere, BlueprintReadWrite, meta = (AllowPrivateAccess = "true"))
		float DangerSphereRadius = 500.f;
	
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = Tactical)
		EFactions myFaction;
	
	UPROPERTY(VisibleAnywhere, BlueprintReadWrite , Category = Tactical, meta = (AllowPrivateAccess = "true"))
		TArray <AHacknSlashCharacter*> Enemies;
	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = Tactical, meta = (AllowPrivateAccess = "true"))
		TArray <AHacknSlashCharacter*> Allies;

};
