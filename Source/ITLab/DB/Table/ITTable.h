// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "ITElement.h"
#include "ITRow.h"
#include "ITTable.generated.h"

class UITColumn;
class UITRow;


USTRUCT()
struct FElementCoord
{
	GENERATED_BODY()

	int32 RowIndex;
	int32 ColumnIndex;
};

USTRUCT()
struct FDataMap
{
	GENERATED_BODY()

	UPROPERTY(Config)
	FElementCoord ElementCoord;
	
	UPROPERTY(Config)
	FElement Element;

	bool operator== (const FDataMap& Right) const
	{
		return ElementCoord.RowIndex == Right.ElementCoord.RowIndex && ElementCoord.ColumnIndex == Right.ElementCoord.ColumnIndex;
	}
};


UCLASS()
class ITLAB_API UITColumn : public UObject
{
	GENERATED_BODY()

public:

	void AddElement(FDataMap InDataMap);
	TArray<FDataMap> GetElements() const { return ColumnData; }
	
private:

	UPROPERTY()
	TArray<FDataMap> ColumnData;
};

UCLASS()
class ITLAB_API UITRow : public UObject
{
	GENERATED_BODY()

public:

	void AddElement(FDataMap InDataMap);
	TArray<FDataMap> GetElements() const { return RowData; }
	
private:

	UPROPERTY()
	TArray<FDataMap> RowData;
};

UCLASS(Config = DB)
class ITLAB_API UITTable : public UObject
{
	GENERATED_BODY()

public:

	void Load();
	void Save();
	
	template<typename Type>
	void AddColumn(const EITElementType& InElementType);

	template<typename Type>
	void AddRow(const EITElementType& InElementType);

	void DeleteRow();
	void DeleteColumn();

	TArray<FDataMap> GetData() const;

	int32 GetRowsCount() const { return RowCount; }
	int32 GetColumnsCount() const { return ColumnCount; }
	
private:

	UPROPERTY(Config)
	TArray<FDataMap> Data;

	UPROPERTY()
	TArray<UITRow*> Rows;

	UPROPERTY()
	TArray<UITColumn*> Columns;

	int32 RowCount = 0;
	int32 ColumnCount = 0;
};

template <typename Type>
void UITTable::AddColumn(const EITElementType& InElementType)
{
	UITColumn* Column = NewObject<UITColumn>(this);
	ColumnCount++;
	for (int32 i = 0; i < RowCount; ++i)
	{
		FElementCoord NewElementCoord;
		NewElementCoord.RowIndex = i;
		NewElementCoord.ColumnIndex = ColumnCount;
		
		Type ElementData = {};
		FElement Element;
		Element.SetElement(InElementType, ElementData);

		FDataMap DataMap;
		DataMap.ElementCoord = NewElementCoord;
		DataMap.Element = Element;

		bool IsExist = false;
		for (const FDataMap& DataElement : Data)
		{
			if (DataElement.ElementCoord.RowIndex == NewElementCoord.RowIndex
				&& DataElement.ElementCoord.ColumnIndex == NewElementCoord.ColumnIndex)
			{
				IsExist = true;
				break;
			}
		}
		if (!IsExist)
		{
			Data.Add(DataMap);
		}
		
		Column->AddElement(DataMap);
	}

	Columns.Add(Column);
}

template <typename Type>
void UITTable::AddRow(const EITElementType& InElementType)
{
	UITRow* Row = NewObject<UITRow>(this);
	
	RowCount++;
	for (int32 i = 0; i < ColumnCount; ++i)
	{
		FElementCoord NewElementCoord;
		NewElementCoord.RowIndex = RowCount;
		NewElementCoord.ColumnIndex = i;

		Type ElementData = {};
		FElement Element;
		Element.SetElement(InElementType, ElementData);

		FDataMap DataMap;
		DataMap.ElementCoord = NewElementCoord;
		DataMap.Element = Element;
		
		bool IsExist = false;
		for (const FDataMap& DataElement : Data)
		{
			if (DataElement.ElementCoord.RowIndex == NewElementCoord.RowIndex
				&& DataElement.ElementCoord.ColumnIndex == NewElementCoord.ColumnIndex)
			{
				IsExist = true;
				break;
			}
		}
		if (!IsExist)
		{
			Data.Add(DataMap);
		}

		Row->AddElement(DataMap);
	}

	Rows.Add(Row);
}

