// Fill out your copyright notice in the Description page of Project Settings.


#include "EnemyTower.h"
#include "Kismet/GameplayStatics.h"
#include "TimerManager.h"
#include "PlayerTank.h"

void AEnemyTower::Tick(float DeltaTime){
    Super::Tick(DeltaTime);
    if(IsFireRange()){
        RotateTurret(Tank->GetActorLocation());
    }
     
}

void AEnemyTower::BeginPlay(){
    Super::BeginPlay();

    Tank = Cast<APlayerTank>(UGameplayStatics::GetPlayerPawn(this, 0));

    GetWorldTimerManager().SetTimer(
        FireRateTimer, 
        this, 
        &AEnemyTower::CheckFireCond, 
        FireRate, 
        true);
}

void AEnemyTower::CheckFireCond(){
    if (Tank == nullptr) return;

    if(IsFireRange() && Tank->bAlive){
        Fire();
    }
     
}

bool AEnemyTower::IsFireRange(){
    float Distance;
    if(Tank){
        Distance = FVector::Dist(GetActorLocation(), Tank->GetActorLocation()); 
        
        if(Distance <= FireRange){
            return true;
        }
    }

    return false;
}

void AEnemyTower::HandleDestruction(){
    Super::HandleDestruction();
    Destroy();
}