// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "TankPawn.h"
#include "PlayerTank.generated.h"

/**
 * 
 */
UCLASS()
class TOONTANKS_API APlayerTank : public ATankPawn
{
	GENERATED_BODY()
public:
	APlayerTank();

	// Called to bind functionality to input
	virtual void SetupPlayerInputComponent(class UInputComponent* PlayerInputComponent) override;

	virtual void Tick(float DeltaTime) override;

	void HandleDestruction();

	APlayerController* GetPlayerController() const {return PlayerController;};

	bool bAlive = true;

protected:
	virtual void BeginPlay() override;
	
private:
	UPROPERTY(VisibleAnywhere, Category = "Camera")
	class USpringArmComponent* ArmComponent;
	UPROPERTY(VisibleAnywhere, Category = "Camera")
	class UCameraComponent* CameraComponent;

	UPROPERTY(EditAnywhere, Category = "Move")
	float speed = 400.f;

	UPROPERTY(EditAnywhere, Category = "Move")
	float turnSpeed = 200.f;
	
	void Move(float value);
	void Turn(float value);

	APlayerController* PlayerController;
};