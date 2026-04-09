// Fill out your copyright notice in the Description page of Project Settings.


#include "TestActor.h"
#include "EnhancedInputComponent.h"

ATestActor::ATestActor()
{

	PrimaryActorTick.bCanEverTick = true;

}


void ATestActor::OnConstruction(const FTransform& Transform)
{
	Super::OnConstruction(Transform);
	GEngine->AddOnScreenDebugMessage(-1, 5.f, FColor::Green, TEXT("I'm constructing it"));
}



void ATestActor::BeginPlay()
{
	Super::BeginPlay();
	GEngine->AddOnScreenDebugMessage(-1, 5.f, FColor::Green, TEXT("I am playing it"));
}


void ATestActor::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);
	;	;
}

void ATestActor::Greeting()
{
	GEngine->AddOnScreenDebugMessage(-1, 5.f, FColor::Green, TEXT("Hello there!"));
}

void ATestActor::Farewell()
{
	GEngine->AddOnScreenDebugMessage(-1, 5.f, FColor::Green, TEXT("Bye Bye there!"));
}

void ATestActor::MoveSetup(UInputComponent* PlayerInputComponent)
{
	if (UEnhancedInputComponent* Input = Cast<UEnhancedInputComponent>(PlayerInputComponent))
	{
		if (AimingInputAction)
		{
			Input->BindAction(AimingInputAction, ETriggerEvent::Triggered, this, &ATestActor::MoveItself);
		}
	}
}

void ATestActor::MoveItself(const FInputActionInstance& Instance)
{
	float InputValue = Instance.GetValue().Get<float>();

	if (FMath::Abs(InputValue) > KINDA_SMALL_NUMBER)
	{
		FVector CurrentLocation = GetActorLocation();
		CurrentLocation.Y += InputValue * MovementSpeed * GetWorld()->DeltaTimeSeconds;

		SetActorLocation(CurrentLocation);

	}

}


