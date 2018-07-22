#encoding "utf-8"
#include <date.cxx>

PP -> Prep Noun;
// WithWhere -> 'в' (Adj<gnc-agr[1]>) Noun<gram='пр', rt, gnc-agr[1]> interp (WhatWhere.Where);
// S -> Date interp (WhatWhere.When) Word* WithWhere;
S -> Noun interp (WhatWhere.What) Verb interp (WhatWhere.Action) PP interp (WhatWhere.Where);
S -> Date interp (Event.Time);
