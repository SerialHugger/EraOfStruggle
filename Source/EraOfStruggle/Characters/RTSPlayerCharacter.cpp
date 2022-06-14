// Fill out your copyright notice in the Description page of Project Settings.


#include "RTSPlayerCharacter.h"
#include "GameFramework/SpringArmComponent.h"
#include "GameFramework/CharacterMovementComponent.h"
#include "Camera/CameraComponent.h"
#include "../Controllers/RTSPlayerController.h"
#include "../Debug.h"

// Sets default values
ARTSPlayerCharacter::ARTSPlayerCharacter()
{
	// Set this character to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

	CameraSpringArmComponent = CreateDefaultSubobject<USpringArmComponent>("Spring Arm Component");
	CameraSpringArmComponent->SetupAttachment(RootComponent);
	CameraSpringArmComponent->bDoCollisionTest = false;

	CameraComponent = CreateDefaultSubobject<UCameraComponent>("Camera Component");
	CameraComponent->SetupAttachment(CameraSpringArmComponent);
	CameraComponent->bUsePawnControlRotation = true; // Controller rotates camera

	// Setup Character Movement
	GetCharacterMovement()->MaxFlySpeed = FlightSpeed; // set default flight speed
	GetCharacterMovement()->BrakingDecelerationFlying = 9999.f; // Instant deceleration
	GetCharacterMovement()->RotationRate = FRotator(720.f, 720.f, 720.f); // Instant turns
	bUseControllerRotationPitch = true;
	bUseControllerRotationRoll = true;
	bUseControllerRotationYaw = true;

}

// Called when the game starts or when spawned
void ARTSPlayerCharacter::BeginPlay()
{
	Super::BeginPlay();
	
	GetCharacterMovement()->SetMovementMode(MOVE_Flying); // movement mode is flying
	GetCharacterMovement()->bCheatFlying = true; // Add a little bit special sauce

	RTSPlayerController = Cast<ARTSPlayerController>(GetController());

	if (RTSPlayerController == nullptr)
	{
		// PrintError todo
	}
}

// Called every frame
void ARTSPlayerCharacter::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

// Called to bind functionality to input
void ARTSPlayerCharacter::SetupPlayerInputComponent(UInputComponent* PlayerInputComponent)
{
	Super::SetupPlayerInputComponent(PlayerInputComponent);
	// Axis Binds
	InputComponent->BindAxis("MoveVertical", this, &ARTSPlayerCharacter::MoveVertical);
	InputComponent->BindAxis("MoveHorizontal", this, &ARTSPlayerCharacter::MoveHorizontal);
	InputComponent->BindAxis("LookAroundZ", this, &ARTSPlayerCharacter::LookAroundZ);
	InputComponent->BindAxis("LookAroundY", this, &ARTSPlayerCharacter::LookAroundY);
	// Action Binds
	InputComponent->BindAction("IncreaseFlightSpeed", IE_Pressed, this, &ARTSPlayerCharacter::IncreaseFlightSpeed);
	InputComponent->BindAction("DecreaseFlightSpeed", IE_Released, this, &ARTSPlayerCharacter::DecreaseFlightSpeed);

}

// Movement control Functions

void ARTSPlayerCharacter::MoveVertical(float AxisVal)
{
	// If there is input
	if (AxisVal != 0)
	{
		AddMovementInput(RTSPlayerController->ControllerForwardVector() * AxisVal);
	}
}

void ARTSPlayerCharacter::MoveHorizontal(float AxisVal)
{
	// If there is input
	if (AxisVal != 0)
	{
		AddMovementInput(RTSPlayerController->ControllerRightVector() * AxisVal);
	}
}

void ARTSPlayerCharacter::LookAroundZ(float AxisVal)
{
	// If there is input
	if (AxisVal != 0)
	{
		AddControllerYawInput(AxisVal * RotationRate);
	}
}

void ARTSPlayerCharacter::LookAroundY(float AxisVal)
{
	// If there is input
	if (AxisVal != 0)
	{
		AddControllerPitchInput(AxisVal * RotationRate);
	}
}

void ARTSPlayerCharacter::IncreaseFlightSpeed()
{
	FlightSpeed = FlightSpeed + FlightSpeedChangeRate;
	if (FlightSpeed > MaxFlightSpeed)
	{
		FlightSpeed = MaxFlightSpeed;
	}
	GetCharacterMovement()->MaxFlySpeed = FlightSpeed;
}

void ARTSPlayerCharacter::DecreaseFlightSpeed()
{
	FlightSpeed = FlightSpeed + FlightSpeedChangeRate;
	if (FlightSpeed < MinFlightSpeed)
	{
		FlightSpeed = MinFlightSpeed;
	}
	GetCharacterMovement()->MaxFlySpeed = FlightSpeed;
}

