// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Blueprint/UserWidget.h"
#include "MainMenu.generated.h"

/**
 * 
 */
UCLASS()
class ULTIMATECOURSE_API UMainMenu : public UUserWidget
{
	GENERATED_BODY()
	
public:
	void Setup();

protected:

	virtual bool Initialize() override;

	UFUNCTION(BlueprintCallable)
	void ExitMainMenu();

	UFUNCTION(BlueprintCallable)
	void ChangeInputSettings();


	UPROPERTY(meta = (ChangeInputSettings))
		class UButton* ChangeInputSettingsButton;
	UPROPERTY(meta = (BindWidget))
		class UButton* ExitButton;
};
