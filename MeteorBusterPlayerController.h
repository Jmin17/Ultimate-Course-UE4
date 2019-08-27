#pragma once

#include "CoreMinimal.h"
#include "GameFramework/PlayerController.h"
#include "MainMenu.h"
#include "SubclassOf.h"
#include "MeteorBusterPlayerController.generated.h"


UCLASS()
class ULTIMATECOURSE_API AMeteorBusterPlayerController : public APlayerController
{

	GENERATED_BODY()

public:
	AMeteorBusterPlayerController();

	void ChangeInputSettings();
protected:
	virtual void BeginPlay() override;

	UPROPERTY(EditAnywhere)
	UMainMenu* MyUserInterface;

	UPROPERTY(EditAnywhere)
	TSubclassOf<UMainMenu> UserInterfaceClass;
};
