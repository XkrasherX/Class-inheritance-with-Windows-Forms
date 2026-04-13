#pragma once

class IProductivityTracker {
public:
	virtual ~IProductivityTracker();
	virtual void DisplayProductivity() const = 0;
	virtual int GetProductivityScore() const = 0;
};