// Copyright 1998-2018 Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Character.h"
#include "CharacterVitals.h"
#include "CharacterStats.h"
#include "MyEnums.h"
#include "HacknSlashCharacter.generated.h"



//TODO Vitals as a separate class
USTRUCT(BlueprintType)
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
};

//TODO base character class with no camera
UCLASS(config=Game)
class AHacknSlashCharacter : public ACharacter
{
	GENERATED_BODY()

	/** Camera boom positioning the camera behind the character */
	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = Camera, meta = (AllowPrivateAccess = "true"))
	class USpringArmComponent* CameraBoom;

	/** Follow camera */
	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = Camera, meta = (AllowPrivateAccess = "true"))
	class UCameraComponent* FollowCamera;
public:
	AHacknSlashCharacter();

	/** Base turn rate, in deg/sec. Other scaling may affect final turn rate. */
	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category=Camera)
	float BaseTurnRate;

	/** Base look up/down rate, in deg/sec. Other scaling may affect final rate. */
	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category=Camera)
	float BaseLookUpRate;
	/** Character Stats and Vitals */
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Stats")
		TArray <FVital> Vitals;

public:

	//** Verification functions
	UFUNCTION(BlueprintCallable, Category = "Stats")
		int32 GetStatInArray( const EVitalNames vitalName);
	//TODO add check if character has vitals instantiated
	//	UFUNCTION(BlueprintCallable, Category = "Stats")
	//	bool CheckVitals(const TArray <UVitals>  myVitals);

	//** Vital Setters
	UFUNCTION(BlueprintCallable, Category = "Stats")
		void SetMaxValue( const EVitalNames vitalName, const float maxValue);

	UFUNCTION(BlueprintCallable, Category = "Stats")
		void SetCurrentValue( const EVitalNames vitalName, const float currentValue);

	UFUNCTION(BlueprintCallable, Category = "Stats")
		void SetRecoveryRate(const EVitalNames vitalName, const float recoveryRate);

	UFUNCTION(BlueprintCallable, Category = "Stats")
		void StatModifyCurrent( const EVitalNames vitalName, const float AddAmount);

	UFUNCTION(BlueprintCallable, Category = "Stats")
		ECharacterStates GetMyCurrentState(const EVitalNames vitalName, const float currentValue);

	//** Vital Getters
	UFUNCTION(BlueprintCallable, Category = "Stats")
		float GetMaxValue( const EVitalNames vitalName);

	UFUNCTION(BlueprintCallable, Category = "Stats")
		float GetCurrentValue( const EVitalNames vitalName);

	UFUNCTION(BlueprintCallable, Category = "Stats")
		float GetCurrentPercent( const EVitalNames vitalName);


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

protected:
	// APawn interface
	virtual void SetupPlayerInputComponent(class UInputComponent* PlayerInputComponent) override;
	// End of APawn interface

public:
	/** Returns CameraBoom subobject **/
	FORCEINLINE class USpringArmComponent* GetCameraBoom() const { return CameraBoom; }
	/** Returns FollowCamera subobject **/
	FORCEINLINE class UCameraComponent* GetFollowCamera() const { return FollowCamera; }
};

