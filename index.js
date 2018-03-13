/* 
 * rmarked-editor
 * @author rainboy
 * */

import markdownEditor from './src/rsimplemde.vue'
import codeEditor from './src/codeEditor.vue'


export default {
  markdownEditor,
  codeEditor,
  install:function install(Vue){
    Vue.component('markdown-editor',markdownEditor)
    Vue.component('code-editor',codeEditor)
  },
};

export {
  markdownEditor,
  codeEditor
};
