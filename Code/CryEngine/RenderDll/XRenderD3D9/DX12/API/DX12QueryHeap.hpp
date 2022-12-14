// Copyright 2001-2016 Crytek GmbH / Crytek Group. All rights reserved.

// -------------------------------------------------------------------------
//  File name:
//  Version:     v1.00
//  Created:     29/09/2015 by Niels Fr?hling
//  Description:
// -------------------------------------------------------------------------
//  History:
//
////////////////////////////////////////////////////////////////////////////
#pragma once
#ifndef __DX12QUERYHEAP__
	#define __DX12QUERYHEAP__

	#include "DX12Base.hpp"

namespace NCryDX12 {

class CQueryHeap : public CDeviceObject
{
public:
	CQueryHeap(CDevice* device);
	virtual ~CQueryHeap();

	bool             Init(CDevice* device, const D3D12_QUERY_HEAP_DESC& desc);
	void             Reset();

	ID3D12QueryHeap* GetD3D12QueryHeap() const { return /*PassAddRef*/ (m_pQueryHeap); }

	UINT             GetType() const           { return m_Desc12.Type; }
	UINT             GetCapacity() const       { return m_Desc12.Count; }

private:
	DX12_PTR(ID3D12QueryHeap) m_pQueryHeap;
	D3D12_QUERY_HEAP_DESC m_Desc12;
};

}

#endif // __DX12QUERYHEAP__
