#include "stdafx.h"//Реализация методов структуры subset 
#include "Combi.h"
#include <algorithm>
#define NINF  ((short)0x8000)
namespace combi
{
	subset::subset(short n)
	{
		this->n = n;
		this->sset = new short[n];
		this->reset();
	};
	void  subset::reset()
	{
		this->sn = 0;
		this->mask = 0;
	};
	short subset::getfirst()
	{
		__int64 buf = this->mask;
		this->sn = 0;
		for (short i = 0; i < n; i++)
		{
			if (buf & 0x1) this->sset[this->sn++] = i;
			buf >>= 1;
		}
		return this->sn;
	};
	short subset::getnext()
	{
		int rc = -1;
		this->sn = 0;
		if (++this->mask < this->count()) rc = getfirst();
		return rc;
	};
	short subset::ntx(short i)
	{
		return  this->sset[i];
	};
	unsigned __int64 subset::count()
	{
		return (unsigned __int64)(1 << this->n);
	};

	///

	xcombination::xcombination(short nn, short mm)
	{
		this->nn = nn;
		this->mm = mm;
		this->sset = new short[mm + 2];
		this->reset();
	}
	void  xcombination::reset()     // сбросить генератор, начать сначала 
	{
		this->nc = 0;
		for (int i = 0; i < this->mm; i++) this->sset[i] = i;
		this->sset[mm] = this->nn;
		this->sset[mm + 1] = 0;
	};
	short xcombination::getfirst()
	{
		return (this->nn >= this->mm) ? this->mm : -1;
	};
	short xcombination::getnext()    // сформировать следующий массив индексов  
	{
		short rc = getfirst();
		if (rc > 0)
		{

			short j;
			for (j = 0; this->sset[j] + 1 == this->sset[j + 1]; ++j)
				this->sset[j] = j;
			if (j >= this->mm) rc = -1;
			else {
				this->sset[j]++;
				this->nc++;

			};

		}
		return rc;
	};
	short xcombination::ntx(short i)
	{
		return this->sset[i];
	};

	unsigned __int64 fact(unsigned __int64 x) { return(x == 0) ? 1 : (x*fact(x - 1)); };

	unsigned __int64 xcombination::count() const
	{
		return (this->nn >= this->mm) ?
			fact(this->nn) / (fact(this->nn - this->mm)*fact(this->mm)) : 0;
	};

	////

	permutation::permutation(short nnn)
	{
		this->nnn = nnn;
		this->sset = new short[nnn];
		this->dart = new bool[nnn];
		this->reset();
	};
	void  permutation::reset()
	{
		this->getfirst();
	};
	__int64  permutation::getfirst()
	{
		this->np = 0;
		for (int i = 0; i < this->nnn; i++)
		{
			this->sset[i] = i; this->dart[i] = L;
		};
		return  (this->nnn > 0) ? this->np : -1;
	};
	__int64  permutation::getnext()   // 
	{
		__int64 rc = -1;
		short maxm = NINF, idx = -1;
		for (int i = 0; i < this->nnn; i++)
		{
			if (i > 0 &&
				this->dart[i] == L &&
				this->sset[i] > this->sset[i - 1] &&
				maxm < this->sset[i])  maxm = this->sset[idx = i];
			if (i < (this->nnn - 1) &&
				this->dart[i] == R &&
				this->sset[i] > this->sset[i + 1] &&
				maxm < this->sset[i])  maxm = this->sset[idx = i];
		};
		if (idx >= 0)
		{
			std::swap(this->sset[idx],
				this->sset[idx + (this->dart[idx] == L ? -1 : 1)]);
			std::swap(this->dart[idx],
				this->dart[idx + (this->dart[idx] == L ? -1 : 1)]);
			for (int i = 0; i < this->nnn; i++)
				if (this->sset[i] > maxm) this->dart[i] = !this->dart[i];
			rc = ++this->np;
		}
		return rc;
	};
	short permutation::ntx(short i) { return  this->sset[i]; };
//	unsigned __int64 fact(unsigned __int64 x) { return (x == 0) ? 1 : (x*fact(x - 1)); };
	unsigned __int64 permutation::count() const { return fact(this->nnn); };

	///
	accomodation::accomodation(short n4, short m4)
	{
		this->n4 = n4;
		this->m4 = m4;
		this->cgen = new xcombination(n4, m4);
		this->pgen = new permutation(m4);
		this->sset = new short[m4];
		this->reset();
	}
	void  accomodation::reset()
	{
		this->na = 0;
		this->cgen->reset();
		this->pgen->reset();
		this->cgen->getfirst();
	};
	short accomodation::getfirst()
	{
		short rc = (this->n4 >= this->m4) ? this->m4 : -1;
		if (rc > 0)
		{
			for (int i = 0; i <= this->m4; i++)
				this->sset[i] = this->cgen->sset[this->pgen->ntx(i)];
		};
		return rc;
	};
	short accomodation::getnext()
	{
		short rc;
		this->na++;
		if ((this->pgen->getnext())> 0) rc = this->getfirst();
		else  if ((rc = this->cgen->getnext())> 0)
		{
			this->pgen->reset();  rc = this->getfirst();
		};
		return rc;
	};
	short accomodation::ntx(short i)
	{
		return this->sset[i];
	};

//	unsigned __int64 fact(unsigned __int64 x) { return (x == 0) ? 1 : (x*fact(x - 1)); };

	unsigned __int64  accomodation::count() const
	{

		return (this->n4 >= this->m4) ?
			fact(this->n4) / fact(this->n4 - this->m4) : 0;
	};
	////

};
