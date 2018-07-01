// Copyright 1998-2018 Epic Games, Inc. All Rights Reserved.

#include "HacknSlashCharacter.h"
#include "HeadMountedDisplayFunctionLibrary.h"
#include "Camera/CameraComponent.h"
#include "Components/CapsuleComponent.h"
#include "Components/InputComponent.h"
#include "GameFramework/CharacterMovementComponent.h"
#include "GameFramework/Controller.h"
#include "GameFramework/SpringArmComponent.h"
#include "Engine/World.h"
#include "CharacterStats.h"

//////////////////////////////////////////////////////////////////////////
// AHacknSlashCharacter

AHacknSlashCharacter::AHacknSlashCharacter()
{
	// Set size for collision capsule
	GetCapsuleComponent()->InitCapsuleSize(42.f, 96.0f);

	// set our turn rates for input
	BaseTurnRate = 45.f;
	BaseLookUpRate = 45.f;

	// Don't rotate when the controller rotates. Let that just affect the camera.
	bUseControllerRotationPitch = false;
	bUseControllerRotationYaw = false;
	bUseControllerRotationRoll = false;

	// Configure character movement
	GetCharacterMovement()->bOrientRotationToMovement = true; // Character moves in the direction of input...	
	GetCharacterMovement()->RotationRate = FRotator(0.0f, 540.0f, 0.0f); // ...at this rotation rate
	GetCharacterMovement()->JumpZVelocity = 600.f;
	GetCharacterMovement()->AirControl = 0.2f;

	// Create a camera boom (pulls in towards the player if there is a collision)
	CameraBoom = CreateDefaultSubobject<USpringArmComponent>(TEXT("CameraBoom"));
	CameraBoom->SetupAttachment(RootComponent);
	CameraBoom->TargetArmLength = 300.0f; // The camera follows at this distance behind the character	
	CameraBoom->bUsePawnControlRotation = true; // Rotate the arm based on the controller

	// Create a follow camera
	FollowCamera = CreateDefaultSubobject<UCameraComponent>(TEXT("FollowCamera"));
	FollowCamera->SetupAttachment(CameraBoom, USpringArmComponent::SocketName); // Attach the camera to the end of the boom and let the boom adjust to match the controller orientation
	FollowCamera->bUsePawnControlRotation = false; // Camera does not rotate relative to arm

	// Note: The skeletal mesh and anim blueprint references on the Mesh component (inherited from Character) 
	// are set in the derived blueprint asset named MyCharacter (to avoid direct content references in C++)
}

//////////////////////////////////////////////////////////////////////////
// Input

void AHacknSlashCharacter::SetupPlayerInputComponent(class UInputComponent* PlayerInputComponent)
{
	// Set up gameplay key bindings
	check(PlayerInputComponent);
	PlayerInputComponent->BindAction("Jump", IE_Pressed, this, &ACharacter::Jump);
	PlayerInputComponent->BindAction("Jump", IE_Released, this, &ACharacter::StopJumping);

	PlayerInputComponent->BindAxis("MoveForward", this, &AHacknSlashCharacter::MoveForward);
	PlayerInputComponent->BindAxis("MoveRight", this, &AHacknSlashCharacter::MoveRight);

	// We have 2 versions of the rotation bindings to handle different kinds of devices differently
	// "turn" handles devices that provide an absolute delta, such as a mouse.
	// "turnrate" is for devices that we choose to treat as a rate of change, such as an analog joystick
	PlayerInputComponent->BindAxis("Turn", this, &APawn::AddControllerYawInput);
	PlayerInputComponent->BindAxis("TurnRate", this, &AHacknSlashCharacter::TurnAtRate);
	PlayerInputComponent->BindAxis("LookUp", this, &APawn::AddControllerPitchInput);
	PlayerInputComponent->BindAxis("LookUpRate", this, &AHacknSlashCharacter::LookUpAtRate);

	// handle touch devices
	PlayerInputComponent->BindTouch(IE_Pressed, this, &AHacknSlashCharacter::TouchStarted);
	PlayerInputComponent->BindTouch(IE_Released, this, &AHacknSlashCharacter::TouchStopped);

	// VR headset functionality
	PlayerInputComponent->BindAction("ResetVR", IE_Pressed, this, &AHacknSlashCharacter::OnResetVR);
}


void AHacknSlashCharacter::OnResetVR()
{
	UHeadMountedDisplayFunctionLibrary::ResetOrientationAndPosition();
}

void AHacknSlashCharacter::TouchStarted(ETouchIndex::Type FingerIndex, FVector Location)
{
		Jump();
}

void AHacknSlashCharacter::TouchStopped(ETouchIndex::Type FingerIndex, FVector Location)
{
		StopJumping();
}

void AHacknSlashCharacter::TurnAtRate(float Rate)
{
	// calculate delta for this frame from the rate information
	AddControllerYawInput(Rate * BaseTurnRate * GetWorld()->GetDeltaSeconds());
}

void AHacknSlashCharacter::LookUpAtRate(float Rate)
{
	// calculate delta for this frame from the rate information
	AddControllerPitchInput(Rate * BaseLookUpRate * GetWorld()->GetDeltaSeconds());
}

void AHacknSlashCharacter::MoveForward(float Value)
{
	if ((Controller != NULL) && (Value != 0.0f))
	{
		// find out which way is forward
		const FRotator Rotation = Controller->GetControlRotation();
		const FRotator YawRotation(0, Rotation.Yaw, 0);

		// get forward vector
		const FVector Direction = FRotationMatrix(YawRotation).GetUnitAxis(EAxis::X);
		AddMovementInput(Direction, Value);
	}
}

void AHacknSlashCharacter::MoveRight(float Value)
{
	if ((Controller != NULL) && (Value != 0.0f))
	{
		// find out which way is right
		const FRotator Rotation = Controller->GetControlRotation();
		const FRotator YawRotation(0, Rotation.Yaw, 0);

		// get right vector 
		const FVector Direction = FRotationMatrix(YawRotation).GetUnitAxis(EAxis::Y);
		// add movement in that direction
		AddMovementInput(Direction, Value);
	}
}
	int32 AHacknSlashCharacter::GetStatInArray( const EVitalNames vitalName)//, int32& index) 
	{
		int32 index;

		for (int32 i = 0; i <= Vitals.Num(); i++) {
			if (vitalName == Vitals[i].StatName)
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
	*/
	//** Vital Setters
	void AHacknSlashCharacter::SetMaxValue( const EVitalNames vitalName, const float maxValue)//, float&  maxValue)
	{
	//maxValue = 0.1f;
		Vitals[GetStatInArray(vitalName)].MaxValue = maxValue;
	}

	void AHacknSlashCharacter::SetCurrentValue( const EVitalNames vitalName, const float currentValue)
	{
		Vitals[GetStatInArray(vitalName)].CurentValue = currentValue;
	}
	
	void AHacknSlashCharacter::SetRecoveryRate(const EVitalNames vitalName, const float recoveryRate)
	{
		Vitals[GetStatInArray(vitalName)].RegenRate = recoveryRate;
	}
	//** Vital Getters
	float AHacknSlashCharacter::GetMaxValue( const EVitalNames vitalName)//, float&  maxValue)
	{
	//maxValue = 0.1f;
	return Vitals[GetStatInArray( vitalName)].MaxValue;
	}

	float AHacknSlashCharacter::GetCurrentValue( const EVitalNames vitalName)
	{
	return Vitals[GetStatInArray( vitalName)].CurentValue;
	}

	float AHacknSlashCharacter::GetCurrentPercent( const EVitalNames vitalName)
	{
	float result = Vitals[GetStatInArray(vitalName)].CurentValue / Vitals[GetStatInArray( vitalName)].MaxValue;
	return result;
	}

	void AHacknSlashCharacter::StatModifyCurrent( const EVitalNames vitalName, const float AddAmount)
	{
	//compare to max value
		
		SetCurrentValue(vitalName, FMath::Clamp(Vitals[GetStatInArray(vitalName)].CurentValue + AddAmount, 0.0f, GetMaxValue(vitalName)));
	}

	ECharacterStates AHacknSlashCharacter::GetMyCurrentState(const EVitalNames vitalName, const float currentValue)
	{
		ECharacterStates myState = ECharacterStates::St_Eager;
		if (GetCurrentPercent(EVitalNames::VN_HP) > 0.50f) {
			//myState = St_Eager;
		}
		return myState;
	}


