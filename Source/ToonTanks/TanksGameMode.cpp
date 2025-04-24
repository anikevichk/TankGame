// Fill out your copyright notice in the Description page of Project Settings.


#include "TanksGameMode.h"
#include "Kismet/GameplayStatics.h"
#include "PlayerTank.h"
#include "EnemyTower.h"
#include "TanksPlayerController.h"

void ATanksGameMode::BeginPlay(){
    Super::BeginPlay();

    HandleGameStart();
}

void ATanksGameMode::ActorDied(AActor* DeadActor){

    APlayerController* PlayerControler = Tank->GetPlayerController();
    if(DeadActor == Tank){
        if(TanksPlayerController){
            Tank->HandleDestruction();
            TanksPlayerController->SetInableInput(false);
        }
        GameOver(false);
    }
    else if (AEnemyTower* Tower = Cast<AEnemyTower>(DeadActor)){
        Tower->HandleDestruction();
        Towers--;
        if (Towers == 0){
            GameOver(true);
        }
    }     
}

void ATanksGameMode::HandleGameStart(){
    Towers = GetNumTowers();
    Tank = Cast<APlayerTank>(UGameplayStatics::GetPlayerPawn(this, 0));
    TanksPlayerController = Cast<ATanksPlayerController>(UGameplayStatics::GetPlayerController(this, 0));
    
    StartGame();

    if(TanksPlayerController){
        TanksPlayerController->SetInableInput(false);
        FTimerHandle PlayerEnableTimerHandle;

        FTimerDelegate PlayerEnableDelegate =FTimerDelegate::CreateUObject(
            TanksPlayerController, 
            &ATanksPlayerController::SetInableInput, 
            true);

        GetWorldTimerManager().SetTimer(PlayerEnableTimerHandle, PlayerEnableDelegate, StartDelay, false);

    }

}

int ATanksGameMode::GetNumTowers(){
    TArray<AActor*> AllTowers;

    UGameplayStatics::GetAllActorsOfClass(this, AEnemyTower::StaticClass(), AllTowers);
    return AllTowers.Num();
}