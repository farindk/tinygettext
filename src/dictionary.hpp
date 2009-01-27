//  $Id$
//
//  tinygettext - A gettext replacement that works directly on .po files
//  Copyright (C) 2006 Ingo Ruhnke <grumbel@gmx.de>
//
//  This program is free software; you can redistribute it and/or
//  modify it under the terms of the GNU General Public License
//  as published by the Free Software Foundation; either version 2
//  of the License, or (at your option) any later version.
//
//  This program is distributed in the hope that it will be useful,
//  but WITHOUT ANY WARRANTY; without even the implied warranty of
//  MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
//  GNU General Public License for more details.
//
//  You should have received a copy of the GNU General Public License
//  along with this program; if not, write to the Free Software
//  Foundation, Inc., 59 Temple Place - Suite 330, Boston, MA  02111-1307, USA.

#ifndef HEADER_DICTIONARY_HPP
#define HEADER_DICTIONARY_HPP

#include <map>
#include <string>
#include "language_def.hpp"

namespace tinygettext {

/** A simple dictionary class that mimics gettext() behaviour. Each
    Dictionary only works for a single language, for managing multiple
    languages and .po files at once use the DictionaryManager. */
class Dictionary
{
private:
  typedef std::map<std::string, std::string> Entries;
  Entries entries;

  typedef std::map<std::string, std::map<int, std::string> > PluralEntries;
  PluralEntries plural_entries;

  Language language;
  std::string charset;

public:
  /** */
  Dictionary(Language language = &lang_en, const std::string& charset = "utf-8");

  /** Return the charset used for this dictionary */
  std::string get_charset() const;

  Language get_language() const;

  /** Translate the string \a msgid to its correct plural form, based
      on the number of items given by \a num. \a msgid2 is \a msgid in
      plural form. */
  std::string translate(const std::string& msgid, const std::string& msgid2, int num);

  /** Translate the string \a msgid. */
  std::string translate(const std::string& msgid);
  /** Translate the string \a msgid. */
  const char* translate(const char* msgid);

  /** Add a translation from \a msgid to \a msgstr to the dictionary,
      where \a msgid is the singular form of the message, msgid2 the
      plural form and msgstrs a table of translations. The right
      translation will be calculated based on the \a num argument to
      translate(). */
  void add_translation(const std::string& msgid, const std::string& msgid2,
                       const std::map<int, std::string>& msgstrs);

  /** Add a translation from \a msgid to \a msgstr to the
      dictionary */
  void add_translation(const std::string& msgid, const std::string& msgstr);
};

} // namespace tinygettext

#endif

/* EOF */
