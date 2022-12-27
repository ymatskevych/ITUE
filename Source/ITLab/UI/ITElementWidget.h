// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Blueprint/UserWidget.h"
#include "Components/EditableTextBox.h"
#include "ITLab/DB/Table/ITElement.h"
#include "ITElementWidget.generated.h"

UCLASS()
class ITLAB_API UITElementWidget : public UUserWidget
{
	GENERATED_BODY()

public:

	virtual void NativeConstruct() override;
	
	void AddElement(FElement InElement);

	void SetElement(EITElementType InElementType, FElement InElement);
	
	UPROPERTY()
	FElement Element;
	
private:

	UFUNCTION()
	void OnTypeCommitted(const FText& InText);

	UFUNCTION()
	void OnValueCommitted(const FText& InText);
	
	UPROPERTY(meta = (BindWidget))
	UEditableTextBox* DropDown;

	UPROPERTY(meta = (BindWidget))
	UEditableTextBox* TextInputBox;

	EITElementType ElementType = EITElementType::None;
};
