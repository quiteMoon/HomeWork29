import React from 'react';
import './Article.css';

const Article = ({ 
  title, author, text, date, titleFont, authorFont, textFont, 
  titleBackground, authorBackground, textBackground, image, 
  titlePosition 
}) => {
  const titleStyles = {
    fontFamily: titleFont.family, color: titleFont.color, fontSize: titleFont.size,
    backgroundColor: titleBackground, textAlign: titlePosition
  };

  return (
    <div className="article">
      {image && <img src={image} alt="Article" />}
      <div className="text-content">
        <h1 style={titleStyles}>{title}</h1>
        <h3 style={{ 
          fontFamily: authorFont.family, color: authorFont.color, fontSize: authorFont.size,
          backgroundColor: authorBackground 
        }}>
          {author}
        </h3>
        <p style={{ 
          fontFamily: textFont.family, color: textFont.color, fontSize: textFont.size,
          backgroundColor: textBackground 
        }}>
          {text}
        </p>
        <small>{date}</small>
      </div>
    </div>
  );
};

export default Article;
