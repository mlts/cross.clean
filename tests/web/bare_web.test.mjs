/* ************************************************************************** */
/*                                                                            */
/*                                                            +#              */
/*    bare_web.test.mjs                                     +##               */
/*                                                         +###+              */
/*    By: lucas <lucas@tsiaraso.com>                     +########+           */
/*                                                           +###+            */
/*    Created: 2026/10/30 09:18:18 by lucas                  ##+              */
/*    Updated: 2026/10/30 09:18:18 by lucas                 #+                */
/*                                                                            */
/* ************************************************************************** */

import assert from 'node:assert/strict';
import { readFile } from 'node:fs/promises';
import test from 'node:test';

const root = new URL('../../apps/bare-web/', import.meta.url);

test('test_bareWeb_markup_exposesTodoJourney', async () => {
  const html = await readFile(new URL('index.html', root), 'utf8');
  assert.match(html, /<h1[^>]*>Todo<\/h1>/);
  assert.match(html, /id="todo-title"/);
  assert.match(html, /id="todo-list"/);
  assert.match(html, /logo-primary\.svg/);
});

test('test_bareWeb_script_usesSharedCorePort', async () => {
  const source = await readFile(new URL('app.js', root), 'utf8');
  assert.match(source, /globalThis\.TodoCore/);
  assert.match(source, /core\.add/);
  assert.match(source, /core\.toggle/);
});
