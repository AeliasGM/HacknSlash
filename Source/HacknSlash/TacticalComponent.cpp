// Fill out your copyright notice in the Description page of Project Settings.
#include "TacticalComponent.h"
#include "HacknSlashCharacter.h"


// Sets default values for this component's properties
UTacticalComponent::UTacticalComponent()
{
	// Set this component to be initialized when the game starts, and to be ticked every frame.  You can turn these features
	// off to improve performance if you don't need them.
	PrimaryComponentTick.bCanEverTick = true;
	
	DangerSphere = CreateDefaultSubobject<USphereComponent>(TEXT("DangerSphere"));
	//DangerSphere->AttachTo(DangerSphere->GetAttachmentRoot(),NAME_None , EAttachLocation::SnapToTargetIncludingScale);
	DangerSphere->InitSphereRadius(DangerSphereRadius);
	DangerSphere->SetCollisionProfileName(TEXT("OverlapAllDynamic"));

}


// Called when the game starts
void UTacticalComponent::BeginPlay()
{
	Super::BeginPlay();


}


// Called every frame
void UTacticalComponent::TickComponent(float DeltaTime, ELevelTick TickType, FActorComponentTickFunction* ThisTickFunction)
{
	Super::TickComponent(DeltaTime, TickType, ThisTickFunction);

	// ...
}

void UTacticalComponent::BeginOverlap(USphereComponent * DangerSphere, AActor * OtherActor, UPrimitiveComponent * OtherComp, int32 OtherBodyIndex, bool bFromSweep, const FHitResult & SweepResult)
{
	AHacknSlashCharacter* ActorInRange = Cast <AHacknSlashCharacter>(OtherActor);
		UE_LOG(LogTemp, Warning, TEXT("Got an overlapping character: $s"), *ActorInRange->GetName());
		auto OtherActorTactical = Cast <UTacticalComponent> (ActorInRange->GetComponentByClass(UTacticalComponent::StaticClass()));
		
		
		if (OtherActorTactical->myFaction == this->myFaction)
			this->Allies.AddUnique(ActorInRange);
		else
			this->Enemies.AddUnique(ActorInRange);
		
}

