// Fill out your copyright notice in the Description page of Project Settings.


#include "ITElementWidget.h"

void UITElementWidget::NativeConstruct()
{
	Super::NativeConstruct();

	DropDown->OnTextChanged.AddDynamic(this, &UITElementWidget::OnTypeCommitted);
	TextInputBox->OnTextChanged.AddDynamic(this, &UITElementWidget::OnValueCommitted);
}

void UITElementWidget::AddElement(FElement InElement)
{
	Element = InElement;
}

void UITElementWidget::SetElement(EITElementType InElementType, FElement InElement)
{
	Element = InElement;

	switch (InElementType)
	{
	case EITElementType::INTEGER:
		{
			DropDown->SetText(FText::FromString(TEXT("0")));
			break;
		}
	case EITElementType::REAL:
		{
			DropDown->SetText(FText::FromString(TEXT("1")));
			break;
		}
	case EITElementType::COLOR:
		{
			DropDown->SetText(FText::FromString(TEXT("2")));
			break;
		}
	case EITElementType::COLORINVL:
		{
			DropDown->SetText(FText::FromString(TEXT("3")));
			break;
		}
	case EITElementType::CHAR:
		{
			DropDown->SetText(FText::FromString(TEXT("4")));
			break;
		}
	case EITElementType::STRING:
		{
			DropDown->SetText(FText::FromString(TEXT("5")));
			break;
		}
		default: return;
	}
	//TextInputBox->SetText(FText::FromString(FString::Printf(TEXT("%d"), Element.ElementTypeDefusor.ElementInt)));
	TextInputBox->SetText(FText::FromString(Element.ElementTypeDefusor.ElementString));
}

void UITElementWidget::OnTypeCommitted(const FText& InText)
{
	if (InText.ToString() == "0")
	{
		ElementType = EITElementType::INTEGER;
	}
	else if (InText.ToString() == "1")
	{
		ElementType = EITElementType::REAL;
	}
	else if (InText.ToString() == "2")
	{
		ElementType = EITElementType::COLOR;
	}
	else if (InText.ToString() == "3")
	{
		ElementType = EITElementType::COLORINVL;
	}
	else if (InText.ToString() == "4")
	{
		ElementType = EITElementType::CHAR;
	}
	else if (InText.ToString() == "5")
	{
		ElementType = EITElementType::STRING;
	} 
}

void UITElementWidget::OnValueCommitted(const FText& InText)
{
	if (ElementType == EITElementType::INTEGER)
	{
		const int32 Integer = FCString::Atoi(*InText.ToString());
		Element.SetElement(EITElementType::INTEGER, Integer);
	}
	else if (ElementType == EITElementType::REAL)
	{
		const int32 Integer = FCString::Atoi(*InText.ToString());
		Element.SetElement(EITElementType::REAL, Integer);
	}
	else if (ElementType == EITElementType::STRING)
	{
		FString String = InText.ToString();
		Element.SetElement(EITElementType::STRING, String);
	}
	// else if (ElementType == EITElementType::REAL)
	// {
	// 	const int32 Integer = FCString::Atoi(*InText.ToString());
	// 	Element->AddElement(EITElementType::REAL, Integer);
	// } 
}
