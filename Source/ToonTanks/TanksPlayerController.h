// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/PlayerController.h"
#include "TanksPlayerController.generated.h"

/**
 * 
 */
UCLASS()
class TOONTANKS_API ATanksPlayerController : public APlayerController
{
	GENERATED_BODY()

public:
	void SetInableInput(bool bPlayerEnabled);
};
