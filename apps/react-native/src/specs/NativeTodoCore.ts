/* ************************************************************************** */
/*                                                                            */
/*                                                            +#              */
/*    NativeTodoCore.ts                                     +##               */
/*                                                         +###+              */
/*    By: lucas <lucas@tsiaraso.com>                     +########+           */
/*                                                           +###+            */
/*    Created: 2026/10/30 09:18:18 by lucas                  ##+              */
/*    Updated: 2026/10/30 09:18:18 by lucas                 #+                */
/*                                                                            */
/* ************************************************************************** */

import type { TurboModule } from 'react-native';
import { TurboModuleRegistry } from 'react-native';

export interface Spec extends TurboModule {
  add(title: string): string;
  list(): readonly string[];
  remove(id: number): void;
  toggle(id: number): string;
}

export default TurboModuleRegistry.getEnforcing<Spec>('TodoCore');

