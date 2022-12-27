// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "ITElement.generated.h"

USTRUCT()
struct FColorInvl
{
	GENERATED_BODY()

	UPROPERTY(Config)
	FColor ColorBegin;

	UPROPERTY(Config)
	FColor ColorEnd;
};

USTRUCT()
struct FElementTypeDefusor
{
	GENERATED_BODY()

	UPROPERTY(Config)
	int32 ElementInt;

	UPROPERTY(Config)
	double ElementReal;

	UPROPERTY(Config)
	FColor ElementColor;

	UPROPERTY(Config)
	FColorInvl ElementColorInvl;

	//UPROPERTY(Config)
	//FChar ElementChar;

	UPROPERTY(Config)
	FString ElementString;
};

UENUM()
enum class EITElementType : uint8
{
	None = 0,
	INTEGER,
	REAL,
	COLOR,
	COLORINVL,
	CHAR,
	STRING
};

USTRUCT()
struct FElement
{
	GENERATED_BODY()

	void SetElement(EITElementType InElementType, int32 InElement);
	void SetElement(EITElementType InElementType, double InElement);
	void SetElement(EITElementType InElementType, FColor InElement);
	void SetElement(EITElementType InElementType, FColorInvl InElement);
	void SetElement(EITElementType InElementType, FString InElement);
	
	UPROPERTY(Config)
	FElementTypeDefusor ElementTypeDefusor;

	UPROPERTY(Config)
	EITElementType ElementType;
};

inline void FElement::SetElement(EITElementType InElementType, int32 InElement)
{
	ElementType = InElementType;
	
	ElementTypeDefusor.ElementInt = InElement;
}

inline void FElement::SetElement(EITElementType InElementType, double InElement)
{
	ElementType = InElementType;
	
	ElementTypeDefusor.ElementReal = InElement;
}

inline void FElement::SetElement(EITElementType InElementType, FColor InElement)
{
	ElementType = InElementType;
	
	ElementTypeDefusor.ElementColor = InElement;
}

inline void FElement::SetElement(EITElementType InElementType, FColorInvl InElement)
{
	ElementType = InElementType;
	
	ElementTypeDefusor.ElementColorInvl = InElement;
}

inline void FElement::SetElement(EITElementType InElementType, FString InElement)
{
	ElementType = InElementType;
	
	ElementTypeDefusor.ElementString = InElement;
}

// template <typename TemplateElementType>
// void UITElement::SetElement(EITElementType InElementType, TemplateElementType InElement)
// {
// 	ElementType = InElementType;
// 	
// 	switch (InElementType)
// 	{
// 	case EITElementType::INTEGER:
// 		{
// 			ElementTypeDefusor.ElementInt = InElement;
// 			break;
// 		}
// 	case EITElementType::REAL:
// 		{
// 			ElementTypeDefusor.ElementReal = InElement;
// 			break;
// 		}
// 	case EITElementType::COLOR:
// 		{
// 			//ElementTypeDefusor.ElementColor = InElement;
// 			break;
// 		}
// 	case EITElementType::COLORINVL:
// 		{
// 			//ElementTypeDefusor.ElementColorInvl = InElement;
// 			break;
// 		}
// 	case EITElementType::CHAR:
// 		{
// 			//ElementTypeDefusor.ElementChar = InElement;
// 			break;
// 		}
// 	case EITElementType::STRING:
// 		{
// 			//ElementTypeDefusor.ElementString = InElement;
// 			break;
// 		}
// 	default: return;
// 	}
// }
