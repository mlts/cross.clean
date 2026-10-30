/* ************************************************************************** */
/*                                                                            */
/*                                                            +#              */
/*    app.js                                                +##               */
/*                                                         +###+              */
/*    By: lucas <lucas@tsiaraso.com>                     +########+           */
/*                                                           +###+            */
/*    Created: 2026/10/30 09:18:18 by lucas                  ##+              */
/*    Updated: 2026/10/30 09:18:18 by lucas                 #+                */
/*                                                                            */
/* ************************************************************************** */

'use strict';

const core = await globalThis.TodoCore();
const form = document.querySelector('#todo-form');
const input = document.querySelector('#todo-title');
const list = document.querySelector('#todo-list');
const error = document.querySelector('#todo-error');

function render() {
  list.replaceChildren(...core.list().map(renderItem));
}

function renderItem(item) {
  const row = document.createElement('li');
  const toggle = document.createElement('button');
  const title = document.createElement('span');
  row.className = item.completed ? 'done' : '';
  toggle.textContent = item.completed ? 'Undo' : 'Done';
  title.textContent = item.title;
  toggle.addEventListener('click', () => toggleItem(item.id));
  row.append(toggle, title);
  return row;
}

function toggleItem(id) {
  core.toggle(id);
  render();
}

function addItem(event) {
  event.preventDefault();
  try {
    core.add(input.value);
    input.value = '';
    error.textContent = '';
    render();
  } catch (cause) {
    error.textContent = cause instanceof Error ? cause.message : 'Add failed';
  }
}

form.addEventListener('submit', addItem);
render();
