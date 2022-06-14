// Fill out your copyright notice in the Description page of Project Settings.


#include "Debug.h"
#include <Engine/World.h>
#include <DrawDebugHelpers.h>
#include "Math/UnrealMathUtility.h"

void UDebug::Log(const FString& debugMessage)
{
	GEngine->AddOnScreenDebugMessage(-1, 5.0f, FColor::Turquoise, debugMessage);
}

void UDebug::Log(float duration_, const FString& debugMessage)
{
	GEngine->AddOnScreenDebugMessage(-1, duration_, FColor::Turquoise, debugMessage);
}

void UDebug::Log(const FString& debugMessage, const FName& value_, float duration_ /*= 3.0f*/)
{
	GEngine->AddOnScreenDebugMessage(-1, duration_, FColor::Turquoise, debugMessage + value_.ToString());
}

void UDebug::Log(const FString& debugMessage, const float value, float duration_ /*= 3.0f*/)
{
	GEngine->AddOnScreenDebugMessage(-1, duration_, FColor::Turquoise, debugMessage + FString::SanitizeFloat(value));
}

void UDebug::Log(const FString& debugMessage, const int32 value, float duration_ /*= 3.0f*/)
{
	GEngine->AddOnScreenDebugMessage(-1, duration_, FColor::Turquoise, debugMessage + FString::FromInt(value));
}

void UDebug::Log(const FString& debugMessage, const bool value, float duration_ /*= 3.0f*/)
{
	GEngine->AddOnScreenDebugMessage(-1, duration_, FColor::Turquoise, debugMessage + (value ? "True" : "False"));
}

void UDebug::Log(const FString& debugMessage, const FVector value, float duration_ /*= 3.0f*/)
{
	GEngine->AddOnScreenDebugMessage(-1, duration_, FColor::Turquoise, debugMessage + value.ToString());
}

void UDebug::Log(const FString& debugMessage, const FRotator value, float duration_ /*= 3.0f*/)
{
	GEngine->AddOnScreenDebugMessage(-1, duration_, FColor::Turquoise, debugMessage + value.ToString());
}

void UDebug::Log(const FString& debugMessage, const FQuat value, float duration_ /*= 3.0f*/)
{
	GEngine->AddOnScreenDebugMessage(-1, duration_, FColor::Turquoise, debugMessage + value.ToString());
}

void UDebug::Error(const FString& debugMessage, float duration_ /*= 60.0f*/)
{
	GEngine->AddOnScreenDebugMessage(-1, 60.0f, FColor::Red, debugMessage);
}

void UDebug::DrawPoint(UWorld* world_, FVector pos_, float lifteTime_ /*= -1.0f*/, float size_ /*= 15.0f*/, FColor color_ /*= FColor::Red*/)
{
	DrawDebugPoint(world_, pos_, size_, color_, false, lifteTime_);
}

void UDebug::DrawLine(UWorld* world_, FVector startPos_, FVector endPos_, float lifteTime_ /*= -1.0f*/, FColor color_ /*= FColor::Green*/)
{
	DrawDebugLine(world_, startPos_, endPos_, color_, false, lifteTime_);
}

void UDebug::DrawSphere(UWorld* world_, FVector pos_,
	float lifteTime_ /*= -1.0f*/, float radius_ /*= 20.0f*/, FColor color_ /*= FColor::Blue*/)
{
	DrawDebugSphere(world_, pos_, radius_, 8, color_, false, lifteTime_);
}

void UDebug::DrawCylinder(UWorld* world_, FVector startPos_, FVector endPos_,
	float lifteTime_ /*= -1.0f*/, float radius_ /*= 5.0f*/, FColor color_ /*= FColor::Blue*/)
{
	DrawDebugSphere(world_, startPos_, 1, 4, color_, false, lifteTime_);
	DrawDebugSphere(world_, endPos_, 1, 4, color_, false, lifteTime_);
	DrawDebugCylinder(world_, startPos_, endPos_, radius_, 8, color_, false, lifteTime_);
}

void UDebug::DrawArrow(UWorld* world_, FVector startPos_, FVector endPos_,
	float lifteTime_ /*= -1.0f*/, float thickness_ /*= 2.0f*/, FColor color_ /*= FColor::Blue*/)
{
	DrawDebugDirectionalArrow(world_, startPos_, endPos_, 150.0f, color_, false, lifteTime_, 0U, thickness_);
}

void UDebug::DrawCapsule(UWorld* world_, FVector pos_, FRotator rot_, float radius_, float halfHeight,
	float lifteTime_ /*= -1.0f*/, FColor color_ /*= FColor::Blue*/)
{
	DrawDebugCapsule(world_, pos_, halfHeight, radius_, rot_.Quaternion(), color_, false, lifteTime_);
}

