/*
 * opencog/generate/DefaultCallback.h
 *
 * Copyright (C) 2020 Linas Vepstas <linasvepstas@gmail.com>
 *
 * This program is free software; you can redistribute it and/or modify
 * it under the terms of the GNU Affero General Public License v3 as
 * published by the Free Software Foundation and including the exceptions
 * at http://opencog.org/wiki/Licenses
 *
 * This program is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.
 *
 * You should have received a copy of the GNU Affero General Public License
 * along with this program; if not, write to:
 * Free Software Foundation, Inc.,
 * 51 Franklin Street, Fifth Floor, Boston, MA 02110-1301 USA.
 */

#ifndef _OPENCOG_DEFAULT_CALLBACK_H
#define _OPENCOG_DEFAULT_CALLBACK_H

#include <opencog/generate/GenerateCallback.h>

namespace opencog
{
/** \addtogroup grp_generate
 *  @{
 */

class DefaultCallback : public GenerateCallback
{
private:
	size_t _stack_depth;
	size_t _effort;
	AtomSpace* _as;
	HandlePairSeq _pole_pairs;

public:
	DefaultCallback(AtomSpace*, const HandlePairSeq&);
	virtual ~DefaultCallback();

	virtual HandleSeq joints(const Handle&);
	virtual bool connect(const Frame&, const Handle&, const Handle&,
	                     const Handle&, const Handle&);

	virtual void push(const Frame&) { _stack_depth++; }
	virtual void pop(const Frame&) { _stack_depth--; }
	virtual bool recurse(const Frame&);
};


/** @}*/
}  // namespace opencog

#endif // _OPENCOG_DEFAULT_CALLBACK_H
