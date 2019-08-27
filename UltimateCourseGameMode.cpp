// Fill out your copyright notice in the Description page of Project Settings.


#include "UltimateCourseGameMode.h"
#include "MeteorBusterPlayerController.h"


AUltimateCourseGameMode::AUltimateCourseGameMode()
{
	// use our custom PlayerController class
	PlayerControllerClass = AMeteorBusterPlayerController::StaticClass();


}