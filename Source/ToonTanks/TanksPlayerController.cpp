// Fill out your copyright notice in the Description page of Project Settings.


#include "TanksPlayerController.h"
#include "GameFramework/Pawn.h"

void ATanksPlayerController::SetInableInput(bool bPlayerEnabled){
    if(bPlayerEnabled){
        GetPawn()->EnableInput(this);
    }
    else{
        GetPawn()->DisableInput(this);
    }
    bShowMouseCursor = bPlayerEnabled;
}