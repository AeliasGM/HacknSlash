// Fill out your copyright notice in the Description page of Project Settings.

#include "Squad.h"
#include "Runtime/Engine/Classes/Engine/TargetPoint.h"
#include "HacknSlashCharacter.h"



// Sets default values
ASquad::ASquad()
{
 	// Set this pawn to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;
	Mesh = CreateOptionalDefaultSubobject<UStaticMeshComponent>("Mesh");
}

// Called when the game starts or when spawned
void ASquad::BeginPlay()
{
	Super::BeginPlay();
		
	FVector Location= GetActorLocation ();
	FRotator Rotation(0.0f, 0.0f, 0.0f);
	FActorSpawnParameters SpawnInfo;
	myTargetPoint = GetWorld()->SpawnActor<ATargetPoint>(Location, Rotation, SpawnInfo);
}

// Called every frame
void ASquad::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);
	if (!ensure(Leader)) {
		UE_LOG(LogTemp, Warning, TEXT("%s, has no leader"), *this->GetName())
			return;
	}
	this->SetActorLocation(Leader->GetActorLocation (), false,nullptr,ETeleportType::None);
}

// Called to bind functionality to input
void ASquad::SetupPlayerInputComponent(UInputComponent* PlayerInputComponent)
{
	Super::SetupPlayerInputComponent(PlayerInputComponent);

}

