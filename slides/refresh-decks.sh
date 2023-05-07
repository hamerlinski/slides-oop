#!/bin/bash
#
# Copyright © 2023 Jakub Piotr Hamerliński
#
# Permission is hereby granted, free of charge, to any person obtaining a copy
# of this software and associated documentation files (the 'Software'), to deal
# in the Software without restriction, including without limitation the rights
# to use, copy, modify, merge, publish, distribute, sublicense, and/or sell
# copies of the Software, and to permit persons to whom the Software is
# furnished to do so, subject to the following conditions:
#
# The above copyright notice and this permission notice shall be included in
# all copies or substantial portions of the Software.
#
# THE SOFTWARE IS PROVIDED 'AS IS', WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
# IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
# FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE
# AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER
# LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM,
# OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN THE
# SOFTWARE.

allDecks=$(ls -d */)

function updateDeck {
  cd $1
  name=${1%/}
  rm -f "$name-dark.pdf"
  rm -f "$name-light.pdf"
  sed -i -e 's/light/dark/g' ./slides.md
  gum spin --spinner dot --title "Exporting dark slides for $name" -- npm run export
  mv "slides-export.pdf" "$name-dark.pdf"
  sed -i -e 's/dark/light/g' ./slides.md
  gum spin --spinner dot --title "Exporting light slides for $name" -- npm run export
  mv "slides-export.pdf" "$name-light.pdf"
  rm -f slides.md-e
  cd ..
}

selection=$(gum choose "all" $(ls -d */))
if [[ "$selection" = "all" ]]; then
  for deck in $allDecks
  do
    updateDeck $deck
  done
else
  updateDeck $selection
fi
