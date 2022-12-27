// Fill out your copyright notice in the Description page of Project Settings.


#include "ITMainWidget.h"

#include "ITElementWidget.h"
#include "Blueprint/WidgetTree.h"
#include "Components/HorizontalBox.h"

void UITMainWidget::NativeConstruct()
{
	Super::NativeConstruct();

	LoadButton->OnClicked.AddDynamic(this, &UITMainWidget::OnLoadButton);
	SaveButton->OnClicked.AddDynamic(this, &UITMainWidget::OnSaveButton);
	
	AddRowButton->OnClicked.AddDynamic(this, &UITMainWidget::OnAddRowButton);
	AddColumnButton->OnClicked.AddDynamic(this, &UITMainWidget::OnAddColumnButton);
	DeleteRowButton->OnClicked.AddDynamic(this, &UITMainWidget::OnDeleteRowButton);
	DeleteColumnButton->OnClicked.AddDynamic(this, &UITMainWidget::OnDeleteColumnButton);
}

void UITMainWidget::CreateVisualDB(AITDatabase* InDatabase)
{
	Database = InDatabase;
	InitDB();
}

void UITMainWidget::InitDB()
{
	const UITTable* Table = Database->GetTable();

	TArray<FDataMap> Data = Table->GetData();

	const int32 RowCount = Table->GetRowsCount();
	const int32 ColumnCount = Table->GetColumnsCount();

	for (int32 i = 1; i < RowCount + 1; ++i)
	{
		UHorizontalBox* RowWidget = WidgetTree->ConstructWidget<UHorizontalBox>();
		for (int32 j = 0; j < ColumnCount; ++j)
		{
			FElement Element;
			for (auto x : Data)
			{
				if (x.ElementCoord.RowIndex == i && x.ElementCoord.ColumnIndex == j)
				{
					Element = x.Element;
				}
			}
			UITElementWidget* ElementWidget = CreateWidget<UITElementWidget>(this, ElementWidgetClass);
			ElementWidget->SetElement(Element.ElementType, Element);
			
			RowWidget->AddChildToHorizontalBox(ElementWidget);
		}
		RowsHolder->AddChildToVerticalBox(RowWidget);
	}
}

void UITMainWidget::OnLoadButton()
{
	Database->Load();
	RowsHolder->ClearChildren();

	InitDB();
}

void UITMainWidget::OnSaveButton()
{
	Database->Save();
}

void UITMainWidget::OnAddRowButton()
{
	Database->GetTable()->AddRow<int32>(EITElementType::INTEGER);

	RowsHolder->ClearChildren();
	InitDB();
}

void UITMainWidget::OnAddColumnButton()
{
	Database->GetTable()->AddColumn<int32>(EITElementType::INTEGER);
	
	RowsHolder->ClearChildren();
	InitDB();
}

void UITMainWidget::OnDeleteRowButton()
{
	Database->GetTable()->DeleteRow();

	RowsHolder->ClearChildren();
	InitDB();
}

void UITMainWidget::OnDeleteColumnButton()
{
	Database->GetTable()->DeleteColumn();

	RowsHolder->ClearChildren();
	InitDB();
}
