// Copyright 1998-2018 Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Character.h"
//#include "CharacterStats.h"
#include "MyEnums.h"
#include "HacknSlashCharacter.generated.h"

//TODO base character class with no camera
UCLASS(config=Game)
class AHacknSlashCharacter : public ACharacter
{
	GENERATED_BODY()

	/** character stats */
	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = "Vitals", meta = (AllowPrivateAccess = "true"))
	class UCharacterStats* myVitals;

public:
	AHacknSlashCharacter();

	/** Base turn rate, in deg/sec. Other scaling may affect final turn rate. */
	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category="Camera")
	float BaseTurnRate;

	/** Base look up/down rate, in deg/sec. Other scaling may affect final rate. */
	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category="Camera")
	float BaseLookUpRate;
	
	/** sphere component */
	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = "Tactical", meta = (AllowPrivateAccess = "true"))
	class USphereComponent* DangerSphere;

	UPROPERTY(Category = "Tactical", EditAnywhere, BlueprintReadWrite, meta = (AllowPrivateAccess = "true"))
	float DangerSphereRadius = 500.f;

protected:

	/** Resets HMD orientation in VR. */
	void OnResetVR();

	/** Called for forwards/backward input */
	void MoveForward(float Value);

	/** Called for side to side input */
	void MoveRight(float Value);

	/** 
	 * Called via input to turn at a given rate. 
	 * @param Rate	This is a normalized rate, i.e. 1.0 means 100% of desired turn rate
	 */
	void TurnAtRate(float Rate);

	/**
	 * Called via input to turn look up/down at a given rate. 
	 * @param Rate	This is a normalized rate, i.e. 1.0 means 100% of desired turn rate
	 */
	void LookUpAtRate(float Rate);

	/** Handler for when a touch input begins. */
	void TouchStarted(ETouchIndex::Type FingerIndex, FVector Location);

	/** Handler for when a touch input stops. */
	void TouchStopped(ETouchIndex::Type FingerIndex, FVector Location);
	

	/** Death of a chahracter. Currently handled by a blueprint Death Event*/
	UFUNCTION(BlueprintCallable, Category = "Stats")
		void Death();

protected:
	// APawn interface
	virtual void SetupPlayerInputComponent(class UInputComponent* PlayerInputComponent) override;
	// End of APawn interface

	/** 
public:
	 Camera boom positioning the camera behind the character
UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = "Camera", meta = (AllowPrivateAccess = "true"))
class USpringArmComponent* CameraBoom;
 */
 /** Follow camera
 UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = "Camera", meta = (AllowPrivateAccess = "true"))
 class UCameraComponent* FollowCamera;
 */
 /**Set up third person camera
	UFUNCTION(BlueprintCallable, Category = "Camera")
		void SetUpCamera();
		*/
	/** Returns CameraBoom subobject **/
//	FORCEINLINE class USpringArmComponent* GetCameraBoom() const { return CameraBoom; }
	/** Returns FollowCamera subobject **/
//	FORCEINLINE class UCameraComponent* GetFollowCamera() const { return FollowCamera; }
};

