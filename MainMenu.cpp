// Fill out your copyright notice in the Description page of Project Settings.


#include "MainMenu.h"
#include "Button.h"
//#include "Engine.h"

void UMainMenu::Setup()
{
	//putting the menu on the screen
	this->AddToViewport();

	UWorld* World = GetWorld();
	APlayerController* PlayerController = World->GetFirstPlayerController();
	
	// this is needed for some reason
	this->bIsFocusable = true;

	// switching the game over to UI input mode and showing the cursor
	FInputModeUIOnly InputModeData;
	InputModeData.SetWidgetToFocus(this->TakeWidget());
	InputModeData.SetLockMouseToViewportBehavior(EMouseLockMode::DoNotLock);

	PlayerController->SetInputMode(InputModeData);

	PlayerController->bShowMouseCursor = true;
}

bool UMainMenu::Initialize()
{
	if (!Super::Initialize())
		return false;

	//binding the exit button click to a fuction
	ExitButton->OnClicked.AddDynamic(this, &UMainMenu::ExitMainMenu);
	ChangeInputSettingsButton->OnClicked.AddDynamic(this, &UMainMenu::ChangeInputSettings);
	//indicating successful initialization
	return true;
}

void UMainMenu::ChangeInputSettings()
{
	UWorld* World = GetWorld();
	APlayerController* PlayerController = World->GetFirstPlayerController();

	Cast<AMeteorBusterPlayerController>(
		PlayerController)->

}

void UMainMenu::ExitMainMenu()
{
	//if (GEngine)
	//	GEngine->AddOnScreenDebugMessage(-1, 1.f, FColor::Green, TEXT("Exit Main Menu executing"));

	UWorld* World = GetWorld();
	APlayerController* PlayerController = World->GetFirstPlayerController();

	//switching the game over to "game only" input mode and hiding the cursor
	// on menu exit
	FInputModeGameOnly InputModeData;
	InputModeData.SetConsumeCaptureMouseDown(true);

	PlayerController->SetInputMode(InputModeData);

	PlayerController->bShowMouseCursor = false;

	this->RemoveFromViewport();
}