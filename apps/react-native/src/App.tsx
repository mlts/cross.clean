/* ************************************************************************** */
/*                                                                            */
/*                                                            +#              */
/*    App.tsx                                               +##               */
/*                                                         +###+              */
/*    By: lucas <lucas@tsiaraso.com>                     +########+           */
/*                                                           +###+            */
/*    Created: 2026/10/30 09:18:18 by lucas                  ##+              */
/*    Updated: 2026/10/30 09:18:18 by lucas                 #+                */
/*                                                                            */
/* ************************************************************************** */

import { useState } from 'react';
import { Button, SafeAreaView, Text, TextInput, View } from 'react-native';
import TodoCore from './specs/NativeTodoCore';

export function App() {
  const [title, setTitle] = useState('');
  const [items, setItems] = useState<readonly string[]>(TodoCore.list());

  const add = () => {
    TodoCore.add(title);
    setTitle('');
    setItems(TodoCore.list());
  };

  return (
    <SafeAreaView>
      <View>
        <Text accessibilityRole="header">Todo</Text>
        <TextInput
          accessibilityLabel="What needs doing?"
          maxLength={120}
          onChangeText={setTitle}
          value={title}
        />
        <Button disabled={!title.trim()} onPress={add} title="Add" />
        {items.map(item => <Text key={item}>{item}</Text>)}
      </View>
    </SafeAreaView>
  );
}
