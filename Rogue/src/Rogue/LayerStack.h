#pragma once

#include "Rogue/Core.h"
#include "Rogue/Layer.h"

namespace Rogue
{
	typedef std::vector<Layer*>::iterator LS_ITERATOR;

	class ROGUE_API LayerStack
	{
	public:
		LayerStack();
		~LayerStack();

		void PushLayer(Layer* layer);
		void PopLayer(Layer* layer);

		void PushOverlay(Layer* overlay);
		void PopOverlay(Layer* overlay);

		LS_ITERATOR begin() { return m_Layers.begin(); }
		LS_ITERATOR end() { return m_Layers.end(); }

	private:
		std::vector<Layer*> m_Layers;
		LS_ITERATOR m_LayerInsert;
	};
}