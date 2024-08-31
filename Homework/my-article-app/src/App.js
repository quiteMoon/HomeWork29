import React from 'react';
import Article from './components/Article';

const App = () => {
  return (
    <Article
      title="Заголовок статті"
      author="Автор"
      text="Текст статті"
      date="31 серпня 2024"
      titleFont={{ family: 'Arial', color: 'blue', size: '24px' }}
      authorFont={{ family: 'Georgia', color: 'gray', size: '18px' }}
      textFont={{ family: 'Verdana', color: 'black', size: '16px' }}
      titleBackground="lightyellow"
      authorBackground="lightgray"
      textBackground="white"
      image="https://letsenhance.io/static/8f5e523ee6b2479e26ecc91b9c25261e/1015f/MainAfter.jpg"
      titlePosition="center"
    />
  );
};

export default App;
