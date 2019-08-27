// Fill out your copyright notice in the Description page of Project Settings.


#include "MeteorBusterPlayerController.h"
#include "UObject/ConstructorHelpers.h"
#include "MainMenu.h"
#include "BaseWidgetBlueprint.h"
#include <stdexcept>


AMeteorBusterPlayerController::AMeteorBusterPlayerController()
{
	// getting the class of our UI Blueprint
	static ConstructorHelpers::FClassFinder<UMainMenu> UserInterface_BPClass(
		TEXT("/Game/Blueprints/UserInterface_BP")
	);

	// saving the class
	UserInterfaceClass = UserInterface_BPClass.Class;

	// throwing error on failure
	if (!UserInterfaceClass)
		throw std::logic_error("epic fail");
}
void AMeteorBusterPlayerController::BeginPlay()
{
	//constructing the widget
	MyUserInterface = CreateWidget<UMainMenu>(this, UserInterfaceClass, "UserInterface");

	//having the widget run some initial setup code
	MyUserInterface->Setup();
}

void AMeteorBusterPlayerController::ChangeInputSettings()
{

}
