#pragma once

#include <memory>
#include <stack>

#include "state.hpp"

namespace Sziad
{
	typedef std::unique_ptr<state> stateRef;

	class stateMachine
	{
	public:
		stateMachine() {}
		~stateMachine() {}

		void addState(stateRef newState, bool isReplacing = true);
		void removeState();
		
		void processStateChanges();

		stateRef &getActiveState();

	private:
		std::stack<stateRef> _states;
		stateRef _newState;
		
		bool _isRemoving;
		bool _isAdding;
		bool _isReplacing;
	};
}