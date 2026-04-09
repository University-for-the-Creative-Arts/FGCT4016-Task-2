// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "InputAction.h"               
#include "InputActionValue.h"          
#include "EnhancedInputSubsystems.h"   
#include "TestActor.generated.h"

UCLASS()
class SEM2UNIVERSITYTASKS_API ATestActor : public AActor
{
	GENERATED_BODY()
	
public:	

	ATestActor();

protected:
	
	virtual void BeginPlay() override;

public:	

	virtual void Tick(float DeltaTime) override;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Movement")
	float MovementSpeed = 600.f;

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = "Input")
	TObjectPtr<UInputAction> AimingInputAction;

	UFUNCTION(BlueprintCallable)
	virtual void Greeting();
	virtual void Farewell();
	virtual void MoveSetup(UInputComponent* PlayerInputComponent);
	virtual void MoveItself(const FInputActionInstance& Instance);

public:
	virtual void OnConstruction(const FTransform& Transform) override;

};
