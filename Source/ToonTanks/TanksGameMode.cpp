// Fill out your copyright notice in the Description page of Project Settings.


#include "TanksGameMode.h"
#include "Kismet/GameplayStatics.h"
#include "PlayerTank.h"
#include "EnemyTower.h"

void ATanksGameMode::BeginPlay(){
    Super::BeginPlay();

    Tank = Cast<APlayerTank>(UGameplayStatics::GetPlayerPawn(this, 0));
}

void ATanksGameMode::ActorDied(AActor* DeadActor){
    APlayerController* PlayerControler = Tank->GetPlayerController();
    if(DeadActor == Tank){
        Tank->HandleDestruction();
        if(PlayerControler){
            Tank->DisableInput(PlayerControler);
            PlayerControler->bShowMouseCursor = false;
        }
    }
    else if (AEnemyTower* Tower = Cast<AEnemyTower>(DeadActor)){
        Tower->HandleDestruction();
    }     
}

