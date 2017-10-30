/* 
 * rmarked-editor
 * @author rainboy
 * */

import markdownEditor './src/rsimplemde.vue'

export default {
  markdownEditor,
  install(Vue){
    Vue.component('markdown-editor',markdownEditor)
  },
};

export {
  markdownEditor
};
