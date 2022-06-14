// Fill out your copyright notice in the Description page of Project Settings.


#include "RTSPlayerController.h"
#include "Kismet/KismetMathLibrary.h"

ARTSPlayerController::ARTSPlayerController()
{
	bShowMouseCursor = true;
	DefaultMouseCursor = EMouseCursor::GrabHand;
}

void ARTSPlayerController::SetupInputComponent()
{
	
}

void ARTSPlayerController::BeginPlay()
{
	InputMode.SetLockMouseToViewportBehavior(EMouseLockMode::LockAlways);
	SetInputMode(InputMode);
}

FVector ARTSPlayerController::ControllerForwardVector()
{
	return UKismetMathLibrary::GetForwardVector(GetControlRotation());
}

FVector ARTSPlayerController::ControllerRightVector()
{
	return UKismetMathLibrary::GetRightVector(GetControlRotation());
}
