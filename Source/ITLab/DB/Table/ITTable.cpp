// Fill out your copyright notice in the Description page of Project Settings.

#pragma region UE_SERIALIZE_DATA
static void LoadSerialized() {}
static void SaveSerialized() {}

#pragma endregion
#include "ITTable.h"

#include "ITColumn.h"

void UITTable::Load()
{
	Data.Empty();

#pragma region UE_DEBUG_SYMBOLS

	EITElementType ETArr[4][3] = {
		{ EITElementType::INTEGER, EITElementType::INTEGER, EITElementType::INTEGER },
		{ EITElementType::INTEGER, EITElementType::REAL, EITElementType::COLOR },
		{ EITElementType::COLORINVL, EITElementType::CHAR, EITElementType::STRING },
		{ EITElementType::INTEGER, EITElementType::INTEGER, EITElementType::INTEGER } };

	FString STRArr[4][3] = {
		{
			"0", "0", "0"
		},
		{
			"1", "123.456789", "(234,0,10)"
		},
		{
			"(123,0,0),(234,0,10)", "c", "base"
		},
		{
			"0", "0", "0"
		}
	};
	
	int32 i = 0;
	for (int32 x = 0; x < 4; ++x)
	{
		for (int32 y = 0; y < 3; ++y)
		{
			FElementCoord ElementCoord;
			ElementCoord.RowIndex = x;
			ElementCoord.ColumnIndex = y;
	
			FElement Element = {}; // da
			//Element.ElementType = EITElementType::INTEGER;
			Element.ElementType = ETArr[x][y];
			//Element.ElementTypeDefusor.ElementString = FString::Printf(TEXT("Penis: %d"), i++);
			Element.ElementTypeDefusor.ElementString = STRArr[x][y];
			FDataMap DataMap;
			
			DataMap.Element = Element;
			DataMap.ElementCoord = ElementCoord;
			Data.Add(DataMap);
		}
	}
#pragma endregion 
	LoadSerialized();
}

void UITTable::Save()
{
	SaveSerialized();
}

void UITTable::DeleteRow()
{
	const UITRow* Row = Rows[Rows.Num() - 1];
	auto DataCopy = Data;
	for (FDataMap ColElements : Row->GetElements())
	{
		int32 i = 0;
		for (const FDataMap& DataEl : DataCopy)
		{
			if (ColElements.ElementCoord.RowIndex == DataEl.ElementCoord.RowIndex
				&& ColElements.ElementCoord.ColumnIndex == DataEl.ElementCoord.ColumnIndex)
			{
				Data.Remove(DataEl);
			}
			else
			{
				//i++;
			}
		}	
	}
	Rows.RemoveAt(Rows.Num() - 1);
	RowCount--;
}

void UITTable::DeleteColumn()
{
	int32 ColIndex = ColumnCount;
	auto DataCopy = Data;
	for (const FDataMap& DataEl : DataCopy)
	{
		if (DataEl.ElementCoord.ColumnIndex == ColIndex)
		{
			Data.Remove(DataEl);
		}
	}
	ColumnCount--;
}

TArray<FDataMap> UITTable::GetData() const
{
	return Data;
}

void UITColumn::AddElement(FDataMap InDataMap)
{
	ColumnData.Add(InDataMap);
}

void UITRow::AddElement(FDataMap InDataMap)
{
	RowData.Add(InDataMap);
}