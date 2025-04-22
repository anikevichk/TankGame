// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "PlayerTank.h"
#include "EnemyTower.generated.h"

/**
 * 
 */
UCLASS()
class TOONTANKS_API AEnemyTower : public APlayerTank
{
	GENERATED_BODY()

public:
	virtual void Tick(float DeltaTime) override;

protected:
	virtual void BeginPlay() override; 

private:
	APlayerTank* Tank;

	UPROPERTY(EditAnywhere, Category="Enemy")
	float FireRange = 1000.f;

	FTimerHandle FireRateTimer;
	float FireRate = 2.f;
	void CheckFireCond();

	bool IsFireRange();
};
