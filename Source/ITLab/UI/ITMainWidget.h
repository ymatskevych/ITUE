// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "ITElementWidget.h"
#include "Blueprint/UserWidget.h"
#include "Components/Button.h"
#include "Components/VerticalBox.h"
#include "ITLab/DB/ITDatabase.h"
#include "ITMainWidget.generated.h"

UCLASS()
class ITLAB_API UITMainWidget : public UUserWidget
{
	GENERATED_BODY()

public:

	virtual void NativeConstruct() override;
	
	UFUNCTION(BlueprintCallable)
	void CreateVisualDB(AITDatabase* InDatabase);

private:

	void InitDB();
	
	UFUNCTION()
	void OnLoadButton();

	UFUNCTION()
	void OnSaveButton();

	UFUNCTION()
	void OnAddRowButton();

	UFUNCTION()
	void OnAddColumnButton();

	UFUNCTION()
	void OnDeleteRowButton();

	UFUNCTION()
	void OnDeleteColumnButton();
	
	UPROPERTY(EditAnywhere)
	TSubclassOf<UITElementWidget> ElementWidgetClass;
	
	UPROPERTY(meta = (BindWidget))
	UVerticalBox* RowsHolder;

	UPROPERTY(meta = (BindWidget))
	UButton* LoadButton;

	UPROPERTY(meta = (BindWidget))
	UButton* SaveButton;

	UPROPERTY(meta = (BindWidget))
	UButton* AddRowButton;

	UPROPERTY(meta = (BindWidget))
	UButton* AddColumnButton;

	UPROPERTY(meta = (BindWidget))
	UButton* DeleteRowButton;

	UPROPERTY(meta = (BindWidget))
	UButton* DeleteColumnButton;

	UPROPERTY()
	AITDatabase* Database;
};
