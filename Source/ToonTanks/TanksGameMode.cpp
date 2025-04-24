// Fill out your copyright notice in the Description page of Project Settings.


#include "TanksGameMode.h"
#include "Kismet/GameplayStatics.h"
#include "PlayerTank.h"
#include "EnemyTower.h"
#include "TanksPlayerController.h"

void ATanksGameMode::BeginPlay(){
    Super::BeginPlay();

    Tank = Cast<APlayerTank>(UGameplayStatics::GetPlayerPawn(this, 0));
    TanksPlayerController = Cast<ATanksPlayerController>(UGameplayStatics::GetPlayerController(this, 0));
}

void ATanksGameMode::ActorDied(AActor* DeadActor){
    APlayerController* PlayerControler = Tank->GetPlayerController();
    if(DeadActor == Tank){
        if(TanksPlayerController){
            TanksPlayerController->SetInableInput(false);
        }
    }
    else if (AEnemyTower* Tower = Cast<AEnemyTower>(DeadActor)){
        Tower->HandleDestruction();
    }     
}

