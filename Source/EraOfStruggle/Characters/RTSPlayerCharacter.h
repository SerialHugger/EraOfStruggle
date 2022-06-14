// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Character.h"
#include "RTSPlayerCharacter.generated.h"

// Alien Classes
class USpringArmComponent;
class UCameraComponent;
class ARTSPlayerController;

UCLASS()
class ERAOFSTRUGGLE_API ARTSPlayerCharacter : public ACharacter
{
	GENERATED_BODY()

public:

	// ----------- Components ----------- \\

	// Camera boom for positioning
	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = "Camera Components")
		USpringArmComponent* CameraSpringArmComponent;

	// The Camera
	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = "Camera Components")
		UCameraComponent* CameraComponent;

	// ------------- Methods ------------- \\
	
	// Sets default values for this character's properties
	ARTSPlayerCharacter();

	// Called every frame
	virtual void Tick(float DeltaTime) override;

	// Called to bind functionality to input
	virtual void SetupPlayerInputComponent(class UInputComponent* PlayerInputComponent) override;

	// ----------- Variables ------------ \\

	// Default Movement speed of camera
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Player Settings")
		float FlightSpeed = 1500.f;

	// Default Rotation sensitivity of camera
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Player Settings")
		float RotationRate = 5.f;

	// Min Movement speed of camera
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Player Settings")
		float FlightSpeedChangeRate = 25.f;

	// Max Movement speed of camera
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Player Settings")
		float MaxFlightSpeed = 3000.f;

	// Min Movement speed of camera
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Player Settings")
		float MinFlightSpeed = 500.f;

protected:

	// ------------- Methods ------------- \\

	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

	// Vertical Movement function for the character
	void MoveVertical(float AxisVal);

	// Horizontal Movement function for the character
	void MoveHorizontal(float AxisVal);

	// For looking around in Z axis
	void LookAroundZ(float AxisVal);

	// For looking around in Y axis
	void LookAroundY(float AxisVal);

	// Use middle mouse button to increase/decrease the flight speed
	void IncreaseFlightSpeed();

	// Use middle mouse button to increase/decrease the flight speed
	void DecreaseFlightSpeed();

	// ----------- Variables ------------ \\

	ARTSPlayerController* RTSPlayerController;

};
